#include<stdio.h>

int main(void){
int H,W,i,I,j,k;
for(i=0;i<10000;i++){		//何回行うか 
	scanf("%d %d",&H,&W);
	if(H!=0){				//四角形として成立しているか 
	for(I=0;I<H;I++){		//建ての回数 
	if(I%2==0){
		for(j=0;j<W;j++){	//横の回数 
			if(j%2==0){
				printf("#");
			}else{
				printf(".");
			}
			
		}
			  }else{
			  for(j=0;j<W;j++){
			if(j%2==0){
				printf(".");
			}else{
				printf("#");
			}
		
		}
			  }
		printf("\n");
			  
			  }
			 }else{
				break;
			}
		printf("\n");	
			}
	return 0;
}

