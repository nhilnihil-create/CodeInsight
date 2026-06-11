#include <bits/stdc++.h>
using namespace std;

const int maxN = 100010;
typedef long long ll;

ll A[maxN], L[maxN], R[maxN], B[maxN];

int main (){
	int n, i;
	ll ans = 1;
	scanf("%d", &n);
	for(i = 0; i <= n; ++i) scanf("%lld", A + i);
	for(i = n, L[n] = R[n] = 0; i; --i){
		L[i - 1] = (A[i] + L[i] + 1) / 2;
		R[i - 1] = A[i] + R[i];
	}
	if(L[0] + A[0] <= 1 && 1 <= R[0] + A[0]){
		R[0] = B[0] = 1;
		for(i = 1; i <= n; ++i){
			B[i] = B[i - 1] * 2;
			if(R[i] > R[i - 1] * 2 - A[i])
				R[i] = R[i - 1] * 2 - A[i];
			if(B[i] > R[i]) B[i] = R[i];
			ans += A[i] + B[i];
			//printf("%d : %lld\n", i, ans);
		}
		printf("%lld\n", ans);
	}
	else puts("-1");
	return 0;
}
