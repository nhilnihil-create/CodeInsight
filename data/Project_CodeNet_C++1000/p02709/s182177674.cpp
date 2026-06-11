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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2005;
int n, q[MX];
ll mem[MX][MX], a[MX];

ll dp (int i, int j) {
	if (i > j) return 0;

	ll &res = mem[i][j];
	if (res != -1) return res;

	int x = q[i + ((n - 1) - j)];

	return res = max(
		dp(i + 1, j) + a[x] * (x - i),
		dp(i, j - 1) + a[x] * (j - x)
	);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn (i, n) cin >> a[i];

	iota(q, q + n, 0);
	sort(q, q + n, [&] (int i, int j) {
		return a[i] > a[j];
	});

	memset(mem, -1, sizeof(mem));
	cout << dp(0, n - 1) << endl;

	return 0;
}
