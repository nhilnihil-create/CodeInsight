#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2010, mod = 1e9 + 7;

int n, k;
LL f[N][N];

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i ++ ) f[i][0] = 1;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= i; j ++ )
			f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % mod;
	
	for (int i = 1; i <= k; i ++ )
		cout << f[k - 1][i - 1] * f[n - k + 1][i] % mod << endl;
	return 0;
}