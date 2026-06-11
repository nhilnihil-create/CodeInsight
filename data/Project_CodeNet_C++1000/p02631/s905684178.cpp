#include<iostream>
#include<array>
#include<vector>
#include<string>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<deque>
#include<algorithm>
#include<cmath>

using namespace std;
#define ll long long
#define ff first
#define ss second
#define e endl

void solve() {
	ll n; cin >> n;
	vector<ll> a, res;
	ll t = -1;
	for (ll i = 0; i < n; i++) {
		ll x; cin >> x; a.push_back(x);
		if (t == -1) t = x;
		else t ^= x;
	}
	
	for (ll i = 0; i < n; i++) {
		res.push_back(t ^ a[i] ^ 0);
		cout << res[i] << e;
	}
}

int main()
{
	//ll t; cin >> t; while (t--)
	solve();
	
}