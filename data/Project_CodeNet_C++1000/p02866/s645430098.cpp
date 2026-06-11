#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <math.h>
#include <bitset>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,s,n)for(ll i = s;i<n;i++)
#define repe(i,s,n)for(ll i = s;i<=n;i++)
#define rep_r(i,s,n)for(ll i = n-1;i>s;i--)
#define rep_re(i,s,n)for(ll i = n-1;i>=s;i--)
ll MOD = 998244353;

ll D[100001] = {};
ll d[100001] = {};
ll Pow(ll n, ll p) {
	if (p == 0)return 1;
	if (p == 1)return n;
	ll t = Pow(n, p / 2);
	if (p & 1) return (t * t % MOD) * n % MOD;
	else return t * t % MOD;
}
int main() {
	ll n; cin >> n;
	ll maxV = 0;
	rep(i, 0, n) {
		cin >> D[i];
		d[D[i]]++;
		maxV = max(D[i], maxV);
	}


	if (d[0] != 1 || D[0] != 0) {
		cout << 0 << endl;
		return 0;
	}

	ll ans = 1;
	repe(i, 2, maxV) {
		if (d[i] == 0) {
			cout << 0 << endl;
			return 0;
		}

		ans = (ans * Pow(d[i-1],d[i])) % MOD;
	}

	cout << ans << endl;
	return 0;
}
