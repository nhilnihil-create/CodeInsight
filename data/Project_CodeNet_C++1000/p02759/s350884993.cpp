#include<stdio.h>


 int main(){
 	int N;
 	scanf("%d", &N);
 	(N%2!=0) ? printf("%d",N/2 + 1) : printf("%d",N/2);
 	return 0;
}