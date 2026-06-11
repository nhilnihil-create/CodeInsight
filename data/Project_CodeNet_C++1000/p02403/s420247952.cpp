#include <stdio.h>

void Rectangle(int H, int W)
{	
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			printf("#");
		}
		printf("\n");
	}
}
		
int main(void)
{
	int H, W;
	
	while(true){
	
		scanf("%d %d",&H, &W);
		
		if(H == 0 && W == 0){
			break;
		}
		
		Rectangle(H, W);
				
		printf("\n");
	}
	
	return 0;
}