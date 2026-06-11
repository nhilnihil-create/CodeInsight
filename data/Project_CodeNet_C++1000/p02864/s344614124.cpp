#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <cmath>
#include <time.h>
#include <unordered_set>
#include <unordered_map>
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define PI 3.14159265
#define RAND (rand()*rand())
#define MAX(x, y) ((x) > (y) ? (x):(y)) 
#define MIN(x, y) ((x) > (y) ? (y):(x))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define CEIL(x, y) (((x) + (y) - 1)/(y))
using namespace std;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
int N, M, K, Q, T;
ll H[305];
ll dp[305][305][305];

ll go(int pos, int idx, int k) {
	if (k < 0) return LINF;
	if (pos > N) return 0ll;
	ll& ret = dp[pos][idx][k];
	if (ret != -1ll) return ret;
	ret = LINF;
	ret = min(go(pos + 1, idx, k - 1), go(pos + 1, pos, k) + MAX(H[pos] - H[idx], 0ll));
	return ret;
}

int main()
{
	int i, j;
	scanf("%d%d", &N, &K);
	for (i = 1; i <= N; ++i) scanf("%lld", &H[i]);
	memset(dp, -1, sizeof(dp));
	ll ans = go(1, 0, K);
	printf("%lld", ans);
	return 0;
}