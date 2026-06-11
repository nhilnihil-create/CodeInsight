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
	ll a, b, c, k;
	cin >> a >> b >> c >> k;
	ll r = min(a, k);
	k -= min(a, k);
	k -= min(b, k);
	r -= min(c, k);
	cout << r << endl;	
	return 0;
}

