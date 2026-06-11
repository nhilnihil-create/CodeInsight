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
	int n; cin >> n;
	vi x(n), y(n);
	rep(i, 0, n) cin >> x[i];
	rep(i, 0, n) cin >> y[i];
	double p1 = 0.0, p2 = 0.0, p3 = 0.0, t;
	int p0 = 0;
	rep(i, 0, n) {
		t = abs(x[i] - y[i]);
		p1 += t;
		p2 += pow(t, 2);
		p3 += pow(t, 3);
		if (p0 < t) p0 = t;
	}
	P(p1);
	P(sqrt(p2));
	P(cbrt(p3));
	P(double(p0));
	return 0;
}