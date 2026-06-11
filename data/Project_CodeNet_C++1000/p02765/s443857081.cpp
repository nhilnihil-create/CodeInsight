#include<stdio.h>

 int main(){
 	int N, R;
 	scanf("%d %d", &N, &R);
 	if(N < 10){
 	 R = R + 100*(10-N);
	 }
	 printf("%d", R);
	 return 0;
 }