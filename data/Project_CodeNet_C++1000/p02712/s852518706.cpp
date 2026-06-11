#include<stdio.h>
int main()
{
	int N;
	long long int X=0;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		if(i%3==0&&i%5==0){
		}
		else if(i%3==0){
		}
		else if(i%5==0){
		}
		else{	
		X=X+i;
		}
	}
		printf("%lld",X);
		
}

