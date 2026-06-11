#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, i, j, k;
	scanf("%d", &N);
	N = (1 << N);
	vector<int> S(N);
	for(i = 0; i < N; i++){
		scanf("%d", &S[i]);
		S[i] *= -1;
	}
	sort(S.begin(), S.end());
	for(i = 1; i < N; i <<= 1){
		sort(S.begin(), S.begin() + i);
		sort(S.begin() + i, S.end());
		for(j = 0, k = i; j < i; swap(S[i + j++], S[k])){
			while(S[j] >= S[k]){
				if(++k == N){
					printf("No\n");
					return 0;
				}
			}
		}
	}
	printf("Yes\n");
	return 0;
}