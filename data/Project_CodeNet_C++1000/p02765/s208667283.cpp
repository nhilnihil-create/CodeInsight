#include<stdio.h>
int main(){
  int N,R;
  scanf("%d", &N);
  scanf("%d", &R);
  if(N>=10){
    printf("%d", R);
  }else{
    printf("%d", R+100*(10-N));
  }
  return 0;
}