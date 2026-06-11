#include <bits/stdc++.h>
using namespace std;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
#define P(x) cout << (x) << endl
#define p(x) cout << (x)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define vv(type, c, m, n, i) vector<vector<type>> c(m, vector<type>(n, i));
#define rep(i,a,n) for(int i=(a), i##_len=(n); i<i##_len; ++i)
#define rrep(i,a,n) for(int i=(a); i>n; --i)
#define len(x) ((int)(x).size())
#define mp make_pair
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
int main() {
	cout << setprecision(13) << fixed;
	while(true) {
		int n; cin >> n;
		if (n == 0) break;
		vd v(n); rep(i, 0, n) cin >> v[i];
		double avg = accumulate(all(v), 0.0) / n;
		double ans = 0.0;
		rep(i, 0, n) {
			ans = ans + pow(v[i] - avg, 2);
		}
		P(sqrt(ans / n));
	}
	return 0;
}