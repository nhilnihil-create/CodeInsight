#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define mp make_pair
#define in insert
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define mod 1000000007
#define sz(v) (int)(v.size())
#define all(x) x.begin(), x.end()
#define prec fixed << setprecision(20)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define test int t; cin >> t; while(t--)

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int, int> mii;
typedef vector<pii> vpi;

void solve() {
	int n;
	cin >> n;
	int sum = 0;
	rep(a, 1, n) {
		rep(b, 1, n) {
			rep(c, 1, n) {
				sum += __gcd(a, __gcd(b, c));
			}
		}
	}
	cout << sum;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// test
	solve();

	return 0;
}