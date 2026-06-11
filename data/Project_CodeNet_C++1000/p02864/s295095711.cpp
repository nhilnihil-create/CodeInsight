#include <bits/stdc++.h>
//<(") 
#define ll long long  
using namespace std;
 
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
 
const ll mod = 1e9 + 7;
const ll siz = 3e2 + 10;
const ll base = 32;
const ll MAXX = 1e18;

ll n, k;
vector<ll> hold;
vector<ll> nxt;
ll change[siz];

ll res[siz][siz][siz];

void compress() {
	sort(nxt.begin(), nxt.end());
	ll l = unique(nxt.begin(), nxt.end()) - nxt.begin();
	nxt.resize(l);
	for (ll i = 0; i <= n; i++) {
		ll val = lower_bound(nxt.begin(), nxt.end(), hold[i]) - nxt.begin() + 1;
		change[val] = hold[i];
		hold[i] = val;
	}
}

ll dp(ll last, ll cur, ll rem) {
	if (cur > n) {
		return 0;
	}
	ll &ans = res[last][cur][rem];
	if (ans != -1) {
		return ans;
	}
	ans = dp(cur, cur + 1, rem) + max(0LL, hold[cur] - hold[last]);
	if (rem > 0) {
		ans = min(ans, dp(last, cur + 1, rem - 1));
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("INP.txt", "r", stdin);
	//freopen("OUT.txt", "w", stdout);
	cin >> n >> k;
	hold.resize(n + 1);
	hold[0] = 0;
	nxt.push_back(0);
	memset(res, -1, sizeof(res));
	for (ll i = 1; i <= n; i++) {
		cin >> hold[i];
		nxt.push_back(hold[i]);
	}
	cout << dp(0, 1, k) << '\n';
	return 0;
}  	 	   		  		 		 	  			  		