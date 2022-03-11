#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GetRandom(int min, int max)
{
    static int flag;

    if (flag == 0) {
        srand((unsigned int)time(NULL));
        flag = 1;
    }

    return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

void main(void){
  int i = 0;
  printf("じゃんけんをする回数を入力してください。：");
  scanf("%d", &i);
//  printf("Debug, 入力直後です\n\n");
  double o = 0;
  int win = 0;
  float win_num = 0;
//  printf("Debug, 変数生成直後です\n\n");
  /*---------------
win = 0：あいこ
win = 1：勝ち
win = 2：負け
  *///-------------
//printf("Debug, ループ手前です。\n\n");
printf("\n");
  do{
//    printf("Debug, ループに入りました\n\n");
    o++;
    printf("%f回目のループ\n", o);
    int janken_1 = GetRandom(1, 3); //ワイ
    int janken_2 = GetRandom(1, 3); //相手
    printf("ワイの値:%d\n", janken_1);
    printf("相手の値:%d\n", janken_2);

    /*
    1：グー
    2：チョキ
    3：パー
    */

    if(janken_1 == 1){ //ワイがグーを出していたら
      if(janken_2 == 1){ //相手もグーを出していたら
        win = 0;
        printf("私：グー, 相手：グー, 結果：あいこ\n\n");
      }
      else if(janken_2 == 2){ //相手がチョキを出していたら
        win = 1;
        win_num++;
        printf("私：グー, 相手：チョキ, 結果：勝ち\n\n");
      }
      else if(janken_2 == 3){ //相手がパーを出していたら
        win = 2;
        printf("私：グー, 相手：パー, 結果：負け\n\n");
      }
    }

    if(janken_1 == 2){ //ワイがチョキを出していたら
      if(janken_2 == 1){ //相手がグーを出していたら
        win = 2;
        printf("私：チョキ, 相手：グー, 結果：負け\n\n");
      }
      else if(janken_2 == 2){ //相手もチョキを出していたら
        win = 0;
        printf("私：チョキ, 相手：チョキ, 結果：あいこ\n\n");
      }
      else if(janken_2 == 3){ //相手がパーを出していたら
        win = 1;
        win_num++;
        printf("私：チョキ, 相手：パー, 結果：勝ち\n\n");
      }
    }

    if(janken_1 == 3){ //ワイがパーを出していたら
      if(janken_2 == 1){ //相手がグーを出していたら
        win = 1;
        win_num++;
        printf("私：パー, 相手：グー, 結果：勝ち\n\n");
      }
      else if(janken_2 == 2){ //相手がチョキを出していたら
        win = 2;
        printf("私：パー, 相手：チョキ, 結果：負け\n\n");
      }
      else if(janken_2 == 3){ //相手もパーを出していたら
        win = 0;
        printf("私：パー, 相手：グー, 結果：あいこ\n\n");
      }
    }
  }while(o != i);

  float percent = 0;
  percent = win_num / o * 100;
  int how_many_janken = 0;
  how_many_janken = o;
  int how_many_win = 0;
  how_many_win = win_num;
  printf("%d回じゃんけんを行い、%d回勝利したので、勝率は %.15f %%です。\n", how_many_janken, how_many_win, percent);
}
