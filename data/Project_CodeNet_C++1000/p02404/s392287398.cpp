#include<cstdio>

int main(){
	int h,w;
	scanf("%d %d", &h, &w);
	while(h && h){
		for(int i = 0; i < h ; i++){
			for(int j = 0; j < w; j++){
				if(i * j && ((i - h + 1) * (j - w + 1)))
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