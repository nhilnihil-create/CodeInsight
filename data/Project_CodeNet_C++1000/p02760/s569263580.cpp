#include<iostream>

using namespace std;

int main(){
  int A[3][3],N,bingo[3][3];
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      cin >> A[i][j];
      bingo[i][j]=0;
    }
  }
  cin >> N;
  for (int k = 0; k < N; k++){
    int b;
    cin >> b;
      for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
          if(A[i][j]==b){
            bingo[i][j]=1;
          }
        }
      }
  }
  
  int flg=0;
  for (int i = 0; i < 3; i++){
      if(bingo[i][0]==1 && bingo[i][1]==1 && bingo[i][2] == 1){
        flg=1;
      }
      if(bingo[0][i]==1 && bingo[1][i]==1 && bingo[2][i] == 1){
        flg=1;
      }
  }

  if(bingo[0][0]==1 && bingo[1][1]==1 && bingo[2][2] == 1){
    flg=1;
  }
  if(bingo[0][2]==1 && bingo[1][1]==1 && bingo[2][0] == 1){
    flg=1;
  }

  if(flg==1){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
}
