#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define pf push_front
#define PI acos(-1)
#define EPS 1e-5
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define forn(i, n) for(ll i=0;i<(ll)n;i++)
#define fi first
#define se second
 

int main() {
	int n;
	cin >> n;
	vector<pii> c(n);
	forn(i, n) {
		int x, y; 
		cin >> x >> y;
		c[i] = {x, y};
	}
	double dist = 0;
	double cnt = 0;
	sort(all(c));
	do {
		for(int i = 0; i+1 < n; i++) {
			dist += sqrt((c[i].fi-c[i+1].fi)*(c[i].fi-c[i+1].fi)+(c[i].se-c[i+1].se)* (c[i].se-c[i+1].se));
		}
		cnt++;
	} while(next_permutation(all(c)));
	double res = dist / cnt;
	cout << fixed << setprecision(10) << res << endl;
	return 0;
}

