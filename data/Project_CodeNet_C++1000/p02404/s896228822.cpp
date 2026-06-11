#include<stdio.h>

int main(void)
{
	int H=1,W=1;
	
	for(;H!=0&&W!=0;){
		
		scanf("%d %d",&H,&W);
		
		for(int s=0;s<H;s++){
			
			for(int t=0;t<W;t++){
				
				if(s==0||s==H-1){
					
					printf("#");
					
				}
				else if(t==0||t==W-1){
					
					printf("#");
					
				}
				else printf(".");
			}
			printf("\n");
		}
		if(H!=0&&W!=0){
			
			printf("\n");
		}
	}
	return 0;
}