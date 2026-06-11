#include <cstdio>

int terms[32]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

int main(){
	int K;
  	scanf("%d",&K);
  	printf("%d\n",terms[K-1]);

	return 0;
}