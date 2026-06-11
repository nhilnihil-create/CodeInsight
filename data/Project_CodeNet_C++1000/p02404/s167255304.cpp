#include<stdio.h>
int main(void)
{
	int a,b,i,j;
	scanf("%d %d",&a,&b);
	while(a!=0 || b!=0){
		for(i=1;i<=a;i++){
			for(j=1;j<=b;j++){
				if(i==1 || j==1 || i==a || j==b){
					printf("#");
				}
				else{
					printf(".");
				}		
			}
				printf("\n");
		}
			printf("\n");
			scanf("%d %d",&a,&b);
	}
	return 0;
}