#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
typedef long double LD;
#define LP(i, a, b) for (LL i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (LL i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8
#define INF 1e9
#define LINF 1e18

LL const MOD = 1e9 + 7;
LL const MaxSize = 1e5 + 5;
//LL const MOD = 998244353;

LL f[MaxSize], invF[MaxSize], r[MaxSize];

void preCalc() {
	r[1] = 1;
	f[1] = 1;
	invF[1] = 1;
	LL m = MOD;

	for (LL i = 2; i < MaxSize; ++i) {
		r[i] = (m - (m / i) * r[m % i] % m) % m;

		f[i] = (i * f[i - 1]) % MOD;
		invF[i] = (r[i] * invF[i - 1]) % MOD;
	}
}

LL choose(LL top, LL bottom) {
	if (top < bottom || top < 0 || bottom < 0)
		return 0;
	if (top == bottom || bottom == 0)
		return 1;

	LL bfs = (invF[bottom] * invF[top - bottom]) % MOD;

	//      cout << "ftop:" << top << " " << f[top] << endl;

	return (f[top] * bfs) % MOD;
}
LL N, K;
SAL t;

LL ways(int v, int p) {
	LL cc = t.at(v).size() - 1;
	LL ans = choose(K - 2, cc);
	LPE(i, 1, cc)
	{
		ans *= i;
		ans %= MOD;
	}

	LP(i, 0, t.at(v).size())
	{
		int u = t.at(v)[i];
		if (u == p)
			continue;
		ans *= ways(u, v);
		ans %= MOD;
	}

	return ans;

}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> N >> K;

	t = SAL(N + 1);

	LP(i, 0, N - 1)
	{
		int a, b;
		cin >> a >> b;
		t.at(a).push_back(b);
		t.at(b).push_back(a);
	}

	preCalc();
	LL rc = t.at(1).size() + 1;
	LL ans = choose(K, rc);

	LPE(i, 1, rc)
	{
		ans *= i;
		ans %= MOD;
	}

	LP(i, 0, t.at(1).size())
	{
		int u = t.at(1)[i];
		ans *= ways(u, 1);
		ans %= MOD;
	}

	cout << ans;

	return 0;

}
