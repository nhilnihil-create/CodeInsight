#include<bits/stdc++.h>
using namespace std;
typedef long long ll; typedef double db;
typedef pair<int, int> pii; typedef pair<ll, ll> pll;
typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pii> vpii; typedef vector<pll> vpll;
#define FOR(n) for(int i=0;i<n;++i)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll gcd(ll a, ll b) { return a % b ? gcd(b, a % b) : b; }
const ll mod = 1e9 + 7; const ll inf = 0x3f3f3f3f;
ll qpow(ll a, ll b) { ll t = 1; while (b != 0) { if (b & 1)t = (t * a) % mod; a = (a * a) % mod; b >>= 1; }return t; }
const ll mx = 1e9;
const ll mmx = 1e18;
signed main() {
	ll x, y, s;
	cin >> s;
	if (s == mmx) {
		cout << 0 << " " << 0 << " " << 0 << " " << mx << " " << mx << " " << mx << endl;
		return 0;
	}
	cout << 0 << " " << 0 << " " << 1 << " " << mx << " ";
	ll a = s / mx;
	ll b = s % mx;
	cout << a + 1 << " " << mx - b << endl;
	return 0;
}