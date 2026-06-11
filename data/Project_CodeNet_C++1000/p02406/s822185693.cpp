#include<stdio.h>
main(){
  int i,n,x;
  scanf("%d",&n);
  for(i=3;i<=n;i++){
    x=i;
    if(x%3==0) printf(" %d",i);
    else if(x%10==3) printf(" %d",i);
    else {
      while(x>10){
        x/=10;
        if(x%10==3){
          printf(" %d",i);
          break;
        }
      }
      continue;
    }
  }
  printf("\n");
  return 0;
}