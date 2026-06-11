#include <stdio.h>

int main(){
	int w,h;
	
	while(1){
		scanf("%d", &h);
		scanf("%d", &w);
		
		if(w == 0 && h == 0)
			return 0;
		
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if( i == 0 || j == 0 || i == (h-1) || j == (w-1))
					printf("#");
				else
					printf(".");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}