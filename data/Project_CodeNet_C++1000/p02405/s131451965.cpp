#include<stdio.h>
int main (){
  int a,b;
  while(1){
    scanf("%d",&a);
    if(a == 0)break;
    scanf("%d",&b);
     for(int i=1;i<=a;i++){
       for(int h=1;h<=b;h++){
	 if(i%2==1 ){
	   if(h%2==1)printf("#");
	   else printf(".");
	 }
	 if(i%2==0){
	   if(h%2==0)printf("#");
	 else printf(".");
	 }
       }
       printf("\n");
     }
     printf("\n");
  }
  return 0;
}
