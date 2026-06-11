#include<stdio.h>
int main(){
  int H;
  int A;
  
  scanf("%d", &H);
  scanf("%d", &A);
  for(int i=1;i<=10001;i++){
    if(H>=1){
      H=H-A;
    }else{
      printf("%d \n", i-1);
      break;
    }
  }
  return 0;
}