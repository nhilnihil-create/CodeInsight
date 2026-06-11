#include <stdio.h>

//????????£?¨?---------------------------
void print_rect(int x, int y);      //????????¢???????????¢??°
//------------------------------------
int main(void)
{
	int H, W;

	while(1){
		scanf("%d %d", &H, &W);
		
		if(H == 0 && W == 0){
			break;
		}
		if(H >= 3 && W >= 3)
			print_rect(H, W);
		
		else{
			print_rect(H, W);
		}
	}
   return 0;
}

//--------------------------------------------
void print_rect(int x, int y)
{
	for(int i = 0; i < x; i++){
			for(int j = 0; j < y; j++){
				if(i == 0 || j == 0 || i == x - 1 || j == y - 1 ){
					printf("#");
				}
				else{
					printf(".");
				}
			}
			printf("\n");
		}
		printf("\n");
}