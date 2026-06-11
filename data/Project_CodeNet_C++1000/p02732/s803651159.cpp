#include <bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define pb push_back
#define fi first
#define se second

using ll = long long;
using G = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;

ll GCD(ll x, ll y){
	return y ? GCD(y, x%y) : x;	
}

int main() {
	int n; cin >> n;
	map<ll ,ll> m;
	ll a[200005];
	rep(i, 0, n){
		cin >> a[i];
		m[a[i]]++;
	}
	ll all = 0;
	for(auto kv: m){
		all += kv.second*(kv.second-1)/2;
	}
	rep(i, 0, n){
		ll x = m[a[i]];
		ll dec = 0;
		if(x>1){
			dec = (x*(x-1)/2) - ((x-1)*(x-2)/2);
		}
		cout << all-dec << endl;
	}
	return 0;
}