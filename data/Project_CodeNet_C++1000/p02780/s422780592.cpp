#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n, k;
	double p,res=0;
	cin >> n >> k;
	vector<double>daicesum(n+1);
	daicesum[0] = 0.0;
	rep(i, n) {
		cin >> p;
		daicesum[i + 1] = daicesum[i] + (p / 2.0 + 0.5);
	}
	rep(i, n - k+1) {
		res = max(res, daicesum[i + k] - daicesum[i]);
	}
	cout << fixed << setprecision(8) << res << endl;
	return 0;
}
