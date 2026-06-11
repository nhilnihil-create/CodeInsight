#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;


using namespace std;



void solve()
{
	int K, Q;
	scanf("%d%d", &K, &Q);
	vector<ll> d(K), dd(K), dd0(K), sdd(K+1), sdd0(K + 1);
	int i;
	for (i = 0; i < K; i++) {
		scanf("%lld", &d[i]);
	}
	vector<ll> N(Q), X(Q), M(Q);
	for (i = 0; i < Q; i++) {
		scanf("%lld%lld%lld", &N[i], &X[i], &M[i]);
	}
	int j;
	for (i = 0; i < Q; i++) {
		sdd[0] = 0;
		sdd0[0] = 0;
		for (j = 0; j < K; j++) {
			dd[j] = d[j] % M[i];
			dd0[j] = (dd[j] == 0 ? 1 : 0);
			sdd[j + 1] = sdd[j] + dd[j];
			sdd0[j + 1] = sdd0[j] + dd0[j];
		}
		ll tmp0 = (N[i]-1) / K;
		ll tmp1 = (N[i]-1) % K;
		ll sum = X[i]%M[i] + sdd[K] * tmp0 + sdd[tmp1];
		ll cnt1=sum / M[i];
		ll cnt0 = sdd0[K] * tmp0 + sdd0[tmp1];
		ll ans = N[i] - 1 - cnt1 - cnt0;
		printf("%lld\n", ans);
	}

    return;
}


int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
