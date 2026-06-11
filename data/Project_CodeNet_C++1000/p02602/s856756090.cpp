#include <stdio.h>
#include <string.h>

int main(){
	int K, N; 
	scanf("%d %d", &N, &K);
	long long int num[N] = {0};
	
	for (int i=0; i<N; i++){
		scanf ("%lld", &num[i]);
	}
	
	for (int i=0; i < N-K ; i++){
		if (num[i] < num[i+K]){   // misal 0 1 2 3 4 5  dan K nya 2
			printf ("Yes\n");	// bandingin aja arr 0 dan arr 2 karena ngebandingin 0*1 dan 1*2
		}
		else {
			printf ("No\n");
		}
	}
return 0;
}