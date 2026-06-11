#include<cstdio>
const short N_MAX = 105;
bool matrix[N_MAX][N_MAX];
int main(){
	int n;
	scanf("%d", &n);
	for(char i=0; i<n;i++){
		int degree, index;
		scanf("%u%u", &index, &degree);
		for(char j=0; j<degree; j++){
			int temp;
			scanf("%d", &temp);
			matrix[index-1][temp-1] = true;
		}
	}
	for(char r=0; r<n; r++){
		for(char c=0;c<n;c++){
			if(c!=0) printf(" ");
			printf("%d", matrix[r][c]);
		}
		printf("\n");
	}
	return 0;
}

