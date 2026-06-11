#include<stdio.h>

int linearSearch(int S[],int T[],int n,int q){
	int k = 0;
	for (int i = 0; i < q; i++){
		for (int j = 0; j < n; j++){
			if (T[i] == S[j]){
				k++;
				break;
			}
		}
	}
	return k;
}

int main(){
	int n, q;
	int S[10000], T[500];
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &S[i]);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++){
		scanf("%d", &T[i]);
	}
	printf("%d\n", linearSearch(S, T, n, q));
	return 0;
}