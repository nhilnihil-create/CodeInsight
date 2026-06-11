#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define all(v)    ((v.begin()),(v.end()))
#define sz(v)     ((int)(v.size()))
#define forv(i, v) for(int i = 0; i < sz(v); ++i)
#define forn(i,n)   for(int i = 0; i < (int)(n); i++)
using namespace std;

typedef long long       ll;
typedef long double     ld;
typedef vector<int>     vi;
typedef vector<double>  vd;
typedef vector< vi >    vii;
typedef vector< vd >    vdd;
typedef vector<string>  vs;

int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

ll modExp(ll base, ll power) {
	if (power == 0) return 1;
	ll cur = modExp(base, power / 2);
	cur = cur * cur;
	if (power & 1) cur = cur * base;
	cur %= MOD;
	return cur;
}

int main()
{
	fast;
	int n;
	cin >> n;
	int p;
	cin >> p;
	string s; cin >> s;
	if (p == 5 || p == 2) {
		ll ans = 0;
		for (int i = 0; i  < n; i++) {
			if ((s[i] - '0') % p == 0) ans += (i + 1);
		}
		cout << ans << endl;
		return 0;
	}

	ll count[p];
	for (int i = 0; i < p; i++) count[i] = 0;
	count[0] = 1;
	int cur = 0;
	MOD = p;
	for (int i = 0; i < n; i++) {
		cur *= 10; cur += s[i] - '0'; cur %= MOD;
		int val = modExp(10, n - 1 - i) * cur; val %= MOD;
		count[val]++;
	}

	ll ans = 0;
	for (int i = 0 ; i  < p; i++) {
		ans += (count[i] * (count[i] - 1)) / 2;

	}
	cout << ans << endl;

	return 0;
}
