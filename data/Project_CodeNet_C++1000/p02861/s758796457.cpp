#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1e9+7;
using namespace std;
using ll = long long;

int main() {
	int n;
	double ans = 0;
	cin >> n;
	vector<int> jun(n);
	rep(i,n) jun[i] = i;
	vector <double> x(n), y(n);
	rep(i,n) cin >> x[i] >> y[i];
	int k = 1;
	rep(i,n) k *= i + 1;
	do {
		rep(i,n-1) {
			double sq = 0;
			sq += pow((x[jun[i]] - x[jun[i+1]]), 2);
			sq += pow((y[jun[i]] - y[jun[i+1]]), 2);
			ans += sqrt(sq);
		}
	} while (next_permutation(jun.begin(), jun.end()));
	ans /= (double)k;
	printf("%.7lf\n", ans);
	return 0;
}