#include<stdio.h>
int main()
{
	int k,x;
	scanf("%d %d",&k,&x);
	k=k*500;
	if(k>=x||k==x){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}
