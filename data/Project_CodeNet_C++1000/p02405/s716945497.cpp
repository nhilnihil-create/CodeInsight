#include<stdio.h>
int main(void)
{
	int H,W;
		int i,j,k,n;
	while(1){
		scanf("%d %d",&H,&W);
		if(H == 0 && W == 0)break;
			for(i = 0; i < H; i++){
				for(j = 0; j < W; j++){
					k = i % 2;
					n = j % 2;
					if(k == 0 && n == 0){
						printf("#");
					}
					else if(k == 1 && n == 0){
						printf(".");
					}
					else if(k == 0 && n == 1){
						printf(".");
					}
					else if(k == 1 && n == 1){
						printf("#");
					}
			}
				printf("\n");
		}
		printf("\n");
	}
	return 0;
}