#include<bits/stdc++.h>
#define int long long
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int a[100][100], b[100][100];
signed main() {
	int n, m, l; cin >> n >> m >> l;
	rep(i, n)rep(j, m)cin >> a[i][j];
	rep(i, m)rep(j, l)cin >> b[i][j];
	rep(i, n) {
		rep(j, l) {
			int sum = 0;
			rep(k, m)sum += a[i][k] * b[k][j];
			if (j)cout << ' ';
			cout << sum;
		}
		cout << endl;
	}
}