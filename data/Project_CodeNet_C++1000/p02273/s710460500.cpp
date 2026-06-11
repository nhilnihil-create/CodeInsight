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
struct Point { double x, y; };
inline void koch(int n, Point a, Point b) {
	if (n == 0) return;
	Point s, t, u;
	double th = M_PI / 3.0;
	s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
	s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
	t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
	t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
	u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
	u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;
	koch(n - 1, a, s);
	cout << s.x << " " << s.y << endl;
	koch(n - 1, s, u);
	cout << u.x << " " << u.y << endl;
	koch(n - 1, u, t);
	cout << t.x << " " << t.y << endl;
	koch(n - 1, t, b);
}
int main() {
	cout << setprecision(8) << fixed;
	int n; cin >> n;
	Point a = { 0, 0 }, b = { 100, 0 };
	cout << a.x << " " << a.y << endl;
	koch(n, a, b);
	cout << b.x << " " << b.y << endl;
	return 0;
}