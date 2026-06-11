#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define PI acos(-1)
#define EPS 1e-5
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define forn(i, n) for(ll i=0;i<(ll)n;i++)
#define fi first
#define se second
 

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> h(n);
	forn(i, n) cin >> h[i];
	vector<set<int>> g(n);
	forn(i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].insert(h[b]);
		g[b].insert(h[a]);
	}
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(sz(g[i]) == 0 || *prev(g[i].end()) < h[i]) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}

