#include<stdio.h>
int main(void)
{
	int a,s,d,f,g,h,j,i;
	while(1){
		scanf("%d %d",&a,&s);
		if(a==0&&s==0)
			break;
		for(i=0;i<s;i++)
			printf("#");
		printf("\n");
		for(i=1;i<a-1;i++){
			printf("#");
			for(j=1;j<s-1;j++)
				printf(".");
			printf("#\n");
		}
		if(a!=1){
			for(i=0;i<s;i++)
				printf("#");
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}