#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using Pair = pair<int, int>;
using Vec = vector<int>;
using Graph = vector<Vec>;

#include <iostream>
using namespace std;

const int MAX = 1000000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++){
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

long long COM(int n, int k){
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int		main(void)
{
	COMinit();
	int x, y;
	cin >> x >> y;
	if ((x + y) % 3)
	{
		cout << 0 << endl;
		return (0);
	}
	int step = (x + y) / 3;
	int right = x - step;
	int down = y - step;
	if (right < 0 || down < 0)
	{
		cout << 0 << endl;
		return (0);
	}
	cout << (((fac[step] * finv[right]) % MOD) * finv[down]) % MOD << endl;
}

