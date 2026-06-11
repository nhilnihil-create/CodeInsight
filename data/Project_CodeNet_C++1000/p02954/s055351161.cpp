#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define reps(i, n) for (int i = 1, i##_len = (int)(n); i <= i##_len; i++)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define repi(i, x) \
	for (auto i = (x).begin(), i##_fin = (x).end(); i != i##_fin; i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a) ? "Yes" : "No")
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int, int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long, long long> P;
typedef vector<P> VP;
template <class T>
inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return 1;
	}
	return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return 1;
	}
	return 0;
}
const long long INFLL = 1LL << 60;
const int INF         = 1 << 30;
const double PI       = acos(-1);
int main() {
	string s;
	int cnt = 0;
	cin >> s;
	Vi ans(s.size(), 0);
	VVi sum(s.size() + 2, Vi(2, 0));
	rep(i, s.size()) {
		// sum[i + 1][0] += sum[i][0];
		if (s[i] == 'R') {
			// sum[i + 1][0]++;
			cnt++;
		} else {
			// sum[i + 1][0] = 0;
			sum[i][0] = cnt;
			cnt       = 0;
		}
	}
	cnt = 0;
	rrep(i, s.size()) {
		// sum[i + 1][1] += sum[i + 2][1];
		if (s[i] == 'L') {
			// sum[i + 1][1]++;
			cnt++;
		} else {
			// sum[i + 1][1] = 0;
			sum[i + 2][1] = cnt;
			cnt           = 0;
		}
	}
	//rep(i, s.size() + 2) { clog << sum[i][0] << " " << sum[i][1] << endl; }
	rep(i, s.size() + 2) {
		if (sum[i][0] != 0) {
			ans[i - 1] += (sum[i][0] + 1) / 2;
			ans[i] += sum[i][0] / 2;
		}
		if (sum[i][1] != 0) {
			ans[i - 1] += (sum[i][1] + 1) / 2;
			ans[i - 2] += sum[i][1] / 2;
		}
	}
	rep(i, ans.size()) {
		cout << ans[i];
		if (i != ans.size() - 1) {
			cout << " ";
		}
	}
	cout << endl;
}