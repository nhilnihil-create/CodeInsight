#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<unordered_map>
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define rep2(i,n) for(int i = (n - 1); i >= 0; i--)
#define PI 3.141592653589793

using namespace std;
using ll = long long;

int to[200000];

int main() {

	ll n, k;
	ll ans = -1000000000000000000;
	cin >> n >> k;

	vector<ll> p(n);
	vector<ll> c(n);
	
	rep(i, n)cin >> p[i];
	rep(i, n)cin >> c[i];
	rep(i, n)p[i]--;

	rep(si, n) {
		ll stot = 0;
		ll x = si;
		vector<ll> s;
		while (1) {
			x = p[x];
			s.push_back(c[x]);
			 stot += c[x];
			if (x == si)break;
		}
		ll l = s.size();
		ll tot = 0;
		rep(i, l) {
			tot += s[i];
			if (i + 1 > k)break;
			ll now = tot;
			if (stot>0) {
				ll e = (k - (i + 1)) / l;
				now += stot * e;
			}
			ans = max(ans, now);
		}
	}

	cout << ans << endl;

	return 0;
}