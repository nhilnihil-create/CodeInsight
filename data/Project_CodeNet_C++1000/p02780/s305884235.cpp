#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<double> p(n);
	rep(i, n) cin >> p[i];
	vector<double> res(n);
	rep(i, n) {
		double tmp = p[i] * (1 + p[i]) / 2;
		tmp /= p[i];
		res[i] = tmp;
		//cout << res[i] << endl;
	}
	vector<double> sum(n + 1);
	rep(i, n) sum[i + 1] = sum[i] + res[i];
	double ans = 0;
	rrep(i, n - k + 2) {
		maxs(ans, sum[i + k - 1] - sum[i - 1]);
	}
	printf("%.10f\n", ans);
	return 0;
}