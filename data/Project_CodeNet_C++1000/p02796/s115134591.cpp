#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, x[MX], l[MX];
ii p[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) {
		cin >> x[i] >> l[i];
		p[i] = {x[i] - l[i], x[i] + l[i]};
	}

	sort(p, p + n, [&] (const ii &x, const ii &y) {
		return x.se < y.se;
	});

	int to = -2e9, res = 0;
	forn (i, n) {
		if (to <= p[i].fi) {
			to = p[i].se;
			res++;
		}
	}

	cout << res << endl;

	return 0;
}
