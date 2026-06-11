#include<bits/stdc++.h>
using namespace std;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;
int N;
i64 A[101010];
i64 subm[101010];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i <= N; ++i) scanf("%lld", A + i);
	subm[N + 1] = 0;
	for (int i = 0; i <= N; ++i) subm[i] = A[i];
	for (int i = N - 1; i >= 0; --i) subm[i] += subm[i + 1];

	long long ret = 0,k = 1;
	for (int i = 0; i <= N; ++i) {
		if (k < A[i]) goto fail;
		ret += k;
		k -= A[i];
		k = min(k * 2, subm[i + 1]);
	}
	if (k != 0) goto fail;
	printf("%lld\n", ret);
	return 0;
fail:
	puts("-1");
	return 0;
}