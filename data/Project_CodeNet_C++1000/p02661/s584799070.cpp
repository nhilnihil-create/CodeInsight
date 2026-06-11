#include <bits/stdc++.h>
//<(") 
#define ll long long   
using namespace std;
 
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
 
const ll mod = 1e9 + 7;
const ll siz =  2e5 + 10;
const ll base = 32;
const ll MAXX = 1e18;

ll n;
vector<ll> a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("INP.txt", "r", stdin);
	//freopen("OUT.txt", "w", stdout);
	cin >> n;
	a.resize(n); b.resize(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i]; cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	if (n % 2 != 0) {
		cout << b[n / 2] - a[n / 2] + 1 << '\n';
	}
	else {
		double x = (b[n / 2] + b[n / 2 - 1]) / 2.0;
		double y = (a[n / 2] + a[n / 2 - 1]) / 2.0;
		//cerr << x << ' ' << y << '\n';
		ll ans = 2 * (x - y) + 1;
		//cerr << x << ' ' << y << '\n';
		cout << ans << '\n';
	}
	return 0;
} 