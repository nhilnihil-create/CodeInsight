#include<stdio.h>
 int main(){
 	int a,b,odd = 0, even = 0;
 	scanf("%d %d",&a,&b);
 	for (int i=2; i<=a; i++){
 		odd =odd + i-1;
	 }
 	for (int i=2; i<=b; i++){
 		even = even+ i-1;
	 }
	 printf("%d",odd+ even);
 	return 0;
 }