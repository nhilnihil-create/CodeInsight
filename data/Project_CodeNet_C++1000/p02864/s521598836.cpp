#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e18;

const int maxn = 333;

long long f[maxn][maxn];

int a[maxn];

int main() {
	//freopen("inp.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	int k = 0;
	cin >> k;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	for(int j=0;j<=n;j++) for(int i=0;i<=n;i++) f[j][i] = inf;
	f[0][0] = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			for(int l = i+1; l<= n; l ++) {
				f[l][j + 1] = min(f[l][j + 1], f[i][j] + max(0, a[l] - a[i]));
			} 
		}
	}	
	
	long long res = inf;
	for(int i=0;i<=n;i++) {
		res = min(res, f[i][n - k]);
	}
	
	cout << res;
	
	return 0;
}
