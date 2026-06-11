#include <stdio.h>
#include <bits/stdc++.h>
int self_x = 10, self_y = 10;
void command(int data[][22], char direction, int move_length) {
  while (move_length > 0) {
    switch(direction) {
    case 'N':
      self_y--;
      break;
    case 'E':
      self_x++;
      break;
    case 'W':
      self_x--;
      break;
    case 'S':
      self_y++;
      break;
    }
    data[self_y][self_x] = 0;
    move_length--;
    // printf("self_x = %d   self_y = %d\n",self_x,self_y);
  }

}

int main(void) {
  int i,j;
  int gem_num; //
  int command_num;//
  
  while (1) {
    int data[22][22] = {{0}};
    int move_length[1000] = {0};
    int gem_x[1000] = {0}, gem_y[1000] = {0};//
    char direction[1000][4] = {{0}};
    self_x = 10, self_y = 10;

    scanf("%d", &gem_num);
    if (gem_num == 0) {
      break;
    }
    for (i = 0; i < gem_num; i++) {
      scanf("%d%d", &gem_x[i], &gem_y[i]);
      data[20-gem_y[i]][gem_x[i]] = 1;
    }
    scanf("%d", &command_num);
    //    printf("command_num = %d\n",command_num);
    for (i = 0; i < command_num; i++) {
      scanf("%s", direction[i]);
      scanf("%d", &move_length[i]);
      //      printf("ss");
    }

    for (i = 0; i < command_num; i++) {
      //1_comand activate
      //printf("debug1\n");
      command(data, direction[i][0], move_length[i]);
      //     printf("debug2\n");

    }
    int flag = 0;
    for (i = 0; i < 21; i++) {
      for (j = 0; j < 21; j++) {
        if (data[i][j] != 0) {
          flag = 1;
          break;
        }
      }
    }
    
    // for (i = 0; i < 21; i++) {
    //   for (j = 0; j < 21; j++) {
    //     printf("%d ",data[i][j]);
    //   }
    //   puts("");
      
    // }









    
    if (flag == 0) {
      printf("Yes\n");
    }
    else {
      printf("No\n");
    }
      
    
  }
  return 0;
}