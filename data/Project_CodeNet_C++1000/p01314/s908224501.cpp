#include <stdio.h>
int main(){
  int N,i,kousuu,cnt,j,n;
  while(1){
    cnt=0;
    scanf("%d",&N);
    if(N==0){
      break;
    }
    for(i=1;i<=N;i++){
      for(j=i;j<=N;j++){
        kousuu=j-i+1;
        n=kousuu;
        if(n>=2 && (i*n+j*n)/2 == N){
          cnt++;
    }
      }
    }
  printf("%d\n",cnt);
  }
  return 0;
}