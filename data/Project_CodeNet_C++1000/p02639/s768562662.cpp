#include<stdio.h>
int main()
{
	int x[6],i;
	for(i=1;i<=5;i++){
		scanf("%d",&x[i]);
	}
	for(i=1;i<=5;i++){
		if(x[i]==0){
			printf("%d\n",i);
		}
	}
	return 0;
}