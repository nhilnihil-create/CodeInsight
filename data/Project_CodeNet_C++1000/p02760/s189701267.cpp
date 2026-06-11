#include<stdio.h>

int main()
{
	int n[3][3], tc;
	int ctr[9] = {0};
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			scanf("%d", &n[i][j]);
		}
	}
	scanf("%d", &tc);
	int b;
	int temp;
	for(int i = 0; i < tc; i++){
		temp = 0;
		scanf("%d", &b);
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				if(b == n[j][k]){
					++ctr[temp];
				}
				++temp;
			}
		}
	}
	int flag = 0;
	for(int i = 0; i < temp; i++){
		if(ctr[0] > 0 && ctr[1] > 0 && ctr[2] > 0){
			flag = 1;
		}else if(ctr[0] > 0 && ctr[3] > 0 && ctr[6] > 0){
			flag = 1;
		}else if(ctr[3] > 0 && ctr[4] > 0 && ctr[5] > 0){
			flag = 1;
		}else if(ctr[6] > 0 && ctr[7] > 0 && ctr[8] > 0){
			flag = 1;
		}else if(ctr[1] > 0 && ctr[4] > 0 && ctr[7] > 0){
			flag = 1;
		}else if(ctr[2] > 0 && ctr[5] > 0 && ctr[8] > 0){
			flag = 1;
		}else if(ctr[0] > 0 && ctr[4] > 0 && ctr[8] > 0){
			flag = 1;
		}else if(ctr[2] > 0 && ctr[4] > 0 && ctr[6] > 0){
			flag = 1;
		}
	}
	if(flag == 1){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
}