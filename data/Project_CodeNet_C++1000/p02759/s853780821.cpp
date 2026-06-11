#include<stdio.h>
int main()
{
	int N;
	int O;
	int Z;
	scanf("%d", &N);
	if(N%2!=0){
		printf("%d",N/2+1);
	}
	else if(N%2==0){
		printf("%d",N/2);
	}
return 0;
}