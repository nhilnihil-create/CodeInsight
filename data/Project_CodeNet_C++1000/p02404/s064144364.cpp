#include<stdio.h>
int main(void)
{
	int H,W,x,y,i;
	char o,p;
	
	o='#';
	p='.';
	
	scanf("%d %d",&H,&W);
	
	while(!(H==0 && W==0)){
		for(i=0;i<W;i++){
		printf("%c",o);
		}
		printf("\n");
			for(x=0;x<H-2;x++){
				printf("%c",o);
				for(y=0;y<W-2;y++){
					printf("%c",p);
					}
				printf("%c",o);
				printf("\n");
			}
			for(i=0;i<W;i++){
				printf("%c",o);
			}
			printf("\n");
			scanf("%d %d",&H,&W);
			printf("\n");
	}	
	return 0;
}