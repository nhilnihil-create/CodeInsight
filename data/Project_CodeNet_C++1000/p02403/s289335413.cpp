#include<stdio.h>
int main(void)
{
	int H,W,x,y,i;
	char op;
	op='#';
	scanf("%d %d",&H,&W);
	while(!(H==0 && W==0)){
		
			for(x=0;H>x;x++){
				
				for(y=0;W>y;y++){
				printf("%c",op);
				}
				printf("\n");
			}
			printf("\n");
			scanf("%d %d",&H,&W);
	}
	return 0;
}