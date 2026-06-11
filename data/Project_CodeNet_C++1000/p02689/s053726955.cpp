#include <bits/stdc++.h>
using namespace std;

signed main(){
	int N, M, i;
	scanf("%d%d", &N, &M);
	vector<int> H(N);
	for(i = 0; i < N; i++){
		scanf("%d", &H[i]);
	}
	vector<int> is_good(N, 1);
	for(i = 0; i < M; i++){
		int A, B;
		scanf("%d%d", &A, &B);
		A--;
		B--;
		if(H[A] <= H[B]){
			is_good[A] = 0;
		}
		if(H[B] <= H[A]){
			is_good[B] = 0;
		}
	}
	int ans = 0;
	for(i = 0; i < N; i++){
		ans += is_good[i];
	}
	printf("%d\n", ans);
	return 0;
}