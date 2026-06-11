#include <iostream>
#include <cstdio>
#define N 2005
using namespace std;

typedef long long ll;
ll M = 1e9 + 7;
ll n, m, a[N], b[N], d[N][N];
int main()
{
	ll i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (i = 1; i <= m; i++) scanf("%lld", &b[i]);
	for (i = 0; i <= n; i++) d[i][0] = 1;
	for (i = 0; i <= m; i++) d[0][i] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
            d[i][j] = (d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + M) % M;
			if (a[i] == b[j]) d[i][j] = (d[i][j] + d[i - 1][j - 1]) % M;
		}
	}
    cout << d[n][m] << endl;
    return 0;
}