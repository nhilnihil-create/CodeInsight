#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=1;i<=n;i++)
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	rep(i, n) v[i] = i;
	vector<double> x(n);
	vector<double> y(n);
	rep(i, n) cin >> x[i] >> y[i];
	int count = 0;
	double dist = 0;
	do {
		rep(i,n-1){
			dist += sqrt((x[v[i+1]] - x[v[i]]) * (x[v[i+1]] - x[v[i]]) + (y[v[i+1]] - y[v[i]])*(y[v[i+1]] - y[v[i]]) );
		}
		count++;
	} while (next_permutation(v.begin(),v.end()));
	double ans = dist / count;
	printf("%.10f", ans);
	return 0;
}

