#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int x[N], y[N];
	rep(i,N) cin >> x[i] >> y[i];
	double d[N][N];
	double ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			d[i][j] = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
			d[i][j] = sqrt(d[i][j]);
			d[j][i] = d[i][j];
		}
	}
	rep(i,N)rep(j,N) ans += d[i][j]/N;
	printf("%.7f\n", ans);

	return 0;
}
