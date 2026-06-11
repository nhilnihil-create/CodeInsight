#include <stdio.h>

int main(){
	int w,h;
	
	while(1){
		int flag = 1, flag2 = -1;
		scanf("%d", &h);
		scanf("%d", &w);
		
		if(w == 0 && h == 0)
			return 0;
		
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(flag == 1)
					printf("#");
				else
					printf(".");
				flag *= (-1);
			}
			flag = flag2;
			flag2 *= (-1);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}