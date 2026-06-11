#include<stdio.h>
int main(){
  int a,i,cou,j;
  while(1){
    scanf("%d",&a);
    if(a==0)break;
    cou=0;
    for(i=a+1;i<=a*2;i++){
      for(j=2;j*j<=i;j++){
	if(i%j==0)break;
      }
      if(j*j>i)cou++;
    }
    printf("%d\n",cou);
  }
  return 0;
}