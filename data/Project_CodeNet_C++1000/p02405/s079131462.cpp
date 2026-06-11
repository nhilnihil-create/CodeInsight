#include<cstdio>

int main(){
	int h,w;
	scanf("%d %d", &h, &w);
	while(h && h){
		for(int i = 0; i < h ; i++){
			for(int j = 0; j < w; j++){
				if((i + j) % 2)
				{
					printf(".");
				}else{
					printf("#");
				}
			}
			printf("\n");
		}
		printf("\n");
		scanf("%d %d", &h, &w);
	}
}