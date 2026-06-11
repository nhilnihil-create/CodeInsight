#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, i, j, k;
	scanf("%d", &N);
	vector<int> S(1 << N);
	for(i = 0; i < (1 << N); i++){
		scanf("%d", &S[i]);
	}
	sort(S.begin(), S.end(), greater<int>());
	for(i = 0; i < N; i++){
//		printf("i = %d\n", i);
		sort(S.begin(), S.begin() + (1 << i), greater<int>());
		sort(S.begin() + (1 << i), S.end(), greater<int>());
/*		for(j = 0; j < (1 << N); j++){
			printf("%d ", S[j]);
		}
		printf("\n");
*/		for(j = 0, k = (1 << i); j < (1 << i); j++){
			while(k < (1 << N) && S[j] <= S[k]){
				k++;
				if(k == (1 << N)){
					printf("No\n");
					return 0;
				}
			}
//			printf("(j, k) = (%d, %d)\n", j, k);
/*			if(k == (1 << N)){
				printf("No\n");
				return 0;
			}
*/			swap(S[(1 << i) + j], S[k]);
		}
	}
	printf("Yes\n");
	return 0;
}