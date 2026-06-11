#include <iostream>
#include <cstdio>
#define N 2005
using namespace std;

long long n, m, M=1e9+7, a[N], b[N], d[N][N];
int main() {
	long long i, j;
	cin >> n >> m;
	for(i=1; i<=n; i++) cin >> a[i];
	for(i=1; i<=m; i++) cin >> b[i];
	for(i=0; i<=n; i++) for(j=0; j<=m; j++) {
		if(i<1 || j<1) d[i][j] = 1;
		else d[i][j] = (d[i-1][j] + d[i][j-1] - (a[i]==b[j] ? 0 : d[i-1][j-1]) + M) % M;
	}
	cout << d[n][m];
	return 0;
}
