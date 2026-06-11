#include <stdio.h>
 
main(){
 int a,b;
 scanf("%d%d",&a,&b);
 
 if(-1000<=a&&b<=1000){
 if(a<b){
 	printf("a < b\n");
 }	
 else if(a>b){
 	printf("a > b\n");
 }
 else if(a==b){
 	printf("a == b\n");
 }
}
 return 0;
}