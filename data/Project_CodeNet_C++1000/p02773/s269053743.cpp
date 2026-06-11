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
	map<string, int> m;
	forn(i, n) {
		string t;
		cin >> t;
		m[t]++;
	}
	int mx = 0;
	for(auto i : m)
		mx = max(mx, i.se);
	for(auto i : m)
		if(i.se == mx)
			cout << i.fi << endl;
	return 0;
}

