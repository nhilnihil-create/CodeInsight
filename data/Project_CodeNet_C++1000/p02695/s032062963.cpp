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
 
int n, m, q;
vector<int> A;
vector<int> a, b, c, d;
int r = 0;

void dfs(int pos, int val) {
	if(pos == n) {
		int sum = 0;
		forn(i, q) {
			if(A[b[i]]-A[a[i]] == c[i])
				sum += d[i];
		}
		r = max(r, sum);
	} else {
		for(int i = val; i <= m; i++) {
			A[pos] = val;
			dfs(pos+1, i);
		}
	}
}

int main() {
	cin >> n >> m >> q;
	A.resize(n);
	a.resize(q);
	b.resize(q);
	c.resize(q);
	d.resize(q);

	forn(i, q) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		a[i]--, b[i]--;
	}	
	dfs(0, 1);

	cout << r << endl;

	return 0;
}

