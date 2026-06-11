#include<stdio.h>
int main(){
 int a,b;
 scanf("%d%d",&a,&b);
 int tmp=0;
 if(b==1){
   printf("0\n");
   return 0;
  }
 for(int i=0;;i++){
  if(a+i*(a-1)>=b){
   printf("%d\n",i+1);
   return 0;
  }
 }
return 0;}