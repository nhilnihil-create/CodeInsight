#include <stdio.h>
int main(){
  int n,x,i,j,k;
  for(;;){
    scanf("%ld %ld",&n,&x);
    if(n==0&&x==0){
      return 0;
    }
    int p=0;
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
        for(k=1;k<=n;k++){
          if(i+j+k==x&&i!=j&&j!=k&&k!=i){
            p++;
          }
        }
      }
    }
    printf("%d\n",p/6);
  }
}