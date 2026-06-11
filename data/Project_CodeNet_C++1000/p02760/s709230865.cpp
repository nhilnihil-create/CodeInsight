#include <stdio.h>

int main(){
	int a[3][3], c[3][3]={0};
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			scanf("%d", &a[i][j]);
		}
	}
	int N;
	scanf("%d", &N);
	int b[N];
	for(int i=0;i<N;i++){
		scanf("%d", &b[i]);
	}
	for(int k=0;k<N;k++){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(a[i][j] == b[k]){
					c[i][j]++;	
				}
			}
		}
	}
	for(int i=0; i<N; i++){
		if(c[i][0]+c[i][1]+c[i][2] == 3){
			printf("Yes\n");
			return 0;
		}
		if(c[0][i]+c[1][i]+c[2][i] == 3){
			printf("Yes\n");
			return 0;
		}
	}
	if(c[0][0]+c[1][1]+c[2][2] == 3){
		printf("Yes\n");
		return 0;
	}
	if(c[2][0]+c[1][1]+c[0][2] == 3){
		printf("Yes\n");
		return 0;
	}
	printf("No\n");
	return 0;
}