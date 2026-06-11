#include <stdio.h>

void Frame(int H, int W)
{	
	for(int y = 0; y < H; y++){
		for(int x = 0; x < W; x++){
			if(y == 0 || y == H - 1){
				printf("#");
			}
			else if(x == 0 || x == W - 1){
				printf("#");
			}
			else{
				printf(".");
			}
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
		
		Frame(H, W);
				
		printf("\n");
	}
	
	return 0;
}