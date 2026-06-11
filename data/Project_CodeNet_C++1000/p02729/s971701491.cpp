#include<stdio.h>

int main(){
	int n,m;
	int sum = 0;
	scanf("%d %d",&n,&m);
	
	for(int i = n-1; i>=0; i--) sum+=i;
	
	for(int i = m-1; i>=0; i--) sum+=i;
	
	printf("%d\n",sum);
	
	return 0;
}