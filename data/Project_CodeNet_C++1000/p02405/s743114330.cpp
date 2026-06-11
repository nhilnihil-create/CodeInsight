#include<stdio.h>
int main(void)
{
	int a,s,d,f,g,h,j,i;
	while(1){
		scanf("%d %d",&a,&s);
		if(a==0&&s==0)
			break;
		for(i=0;i<a;i++){
			for(j=0;j<s;j++){
				if((i+j)%2==1)
					printf(".");
				else
					printf("#");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}