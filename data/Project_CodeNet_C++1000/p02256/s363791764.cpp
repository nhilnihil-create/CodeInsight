#include<stdio.h>
main(){
  int a,b,m;
  scanf("%d %d",&a,&b);
  while(true){
    m = a%b;
    if(m==0){
      printf("%d\n%",b);
      break;
    }
    a = b;
    b = m;
  }
}