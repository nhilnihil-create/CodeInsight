#include<stdio.h>

int main(void)
{
	int W=1,H=1;
	
	for(;W!=0&&H!=0;){
		
		scanf("%d %d",&H,&W);
		
		for(int s=0;s<H;s++){
			
			for(int t=0;t<W;t++){
				
				printf("#");
				
			}
			printf("\n");
		}
		if(H!=0&&W!=0){
			
			printf("\n");
		}
	}
	
	return 0;
}