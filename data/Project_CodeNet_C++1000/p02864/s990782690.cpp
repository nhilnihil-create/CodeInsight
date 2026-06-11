#include <iostream>
#include <cstdio>
#define N 305
using namespace std;
typedef long long ll;

ll n, k, h[N], d[N][N];
int main() {
	int i, j, l;
	cin >> n >> k;
	for(j=1; j<=n; j++) {
		cin >> h[j];
		d[0][j] = 4e18;
	}
	for(i=1; i<=n+1; i++) for(j=0; j<=k; j++) {
		d[i][j] = 4e18;
		for(l=0; l<=k; l++) {
			if(i-1-l<0 || j-l<0) break;
			d[i][j] = min(d[i][j], d[i-1-l][j-l] + max(0LL, h[i] - h[i-1-l]));
		}
	}
	cout << d[n+1][k];
	return 0;
}