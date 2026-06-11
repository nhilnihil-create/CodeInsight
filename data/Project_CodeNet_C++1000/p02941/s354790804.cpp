#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX], b[MX];
ll res;
queue<int> q;

bool valid (int i) {
	return b[i] > a[i] && b[i] > b[(i - 1 + n) % n] + b[(i + 1) % n];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) cin >> a[i];
	forn (i, n) cin >> b[i];
	forn (i, n) if (valid(i)) q.push(i);

	while (q.size()) {
		int i = q.front(); q.pop();
		int x = (i - 1 + n) % n;
		int y = (i + 1) % n;

		int d = max(1, (b[i] - a[i]) / (b[x] + b[y]));
		res += d;
		b[i] -= d * (b[x] + b[y]);

		if (valid(i)) q.push(i);
		if (valid(x)) q.push(x);
		if (valid(y)) q.push(y);
	}

	forn (i, n) if (a[i] != b[i]) {
		cout << -1 << endl;
		return 0;
	}

	cout << res << endl;

	return 0;
}
