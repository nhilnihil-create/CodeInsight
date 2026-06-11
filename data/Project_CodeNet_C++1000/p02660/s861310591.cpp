#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

typedef pair<ll, ll> pll;

int main() {
	ll n;
	cin >> n;
	vector<pii> v;
	ll c = n;
	for (ll i = 2; i * i <= c; i++) {
		if (c % i == 0) {
			pll p;
			p.first = i;
			p.second = 0;
			while (c % i == 0) {
				p.second++;
				c /= i;
			}
			v.push_back(p);
		}
	}
	if (c != 1) v.push_back(pll(c, 1));

	ll ans = 0;
	for (auto p: v) {
		ll c = 1;
		ll x = p.second;
		while (c <= x) {
			x -= c;
			c++;
			ans++;
		}
	}
	cout << ans << endl;
}