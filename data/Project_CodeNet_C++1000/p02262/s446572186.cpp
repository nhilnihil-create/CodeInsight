#include <stdio.h>

int cnt;
int m;
int G[1000001];

int make_g(int n){
	unsigned sh = 0;
	for(unsigned i = 1; (1<<i) <= n; i++){
		sh = i;
	}
	for(int i = 0; i <= sh; i++){
		G[i] = 1<<(sh-i);
	}
	return sh + 1;
}
void insertionSort(int *A,int n,int g){
	for(int i = g; i < n; i++){
		int v = A[i];
		int j = i - g;
		while(j >= 0 && A[j] > v){
			A[j+g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j+g] = v;
	}
}

void shellSort(int *A,int n){
	cnt = 0;
	m =  make_g(n);
	//G = ??
	for(int i = 0; i < m; i++){
		insertionSort(A,n,G[i]);
	}
}

int main(){
	int n;
	int A[1000001];
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&A[i]);
	}
	shellSort(A,n);
	
	printf("%d\n",m);
	printf("%d",G[0]);
	for(int i = 1; i < m; i++){
		printf(" %d",G[i]);
	}
	printf("\n%d\n",cnt);
	for(int i = 0; i < n; i++){
		printf("%d\n",A[i]);
	}
	return 0;
}


