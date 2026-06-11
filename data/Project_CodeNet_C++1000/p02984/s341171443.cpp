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
	ll n; cin >> n;
	ll a[100005];
	ll sum = 0;
	ll even_sum = 0;
	rep(i, 1, n+1) {
		cin >> a[i];
		sum += a[i];
		if(i%2==0) even_sum += a[i];
	}
	ll ans[100005];
	ans[1] = sum - 2*even_sum;
	rep(i, 2, n+1){
		ans[i] = 2*a[i-1]-ans[i-1];
	}
	rep(i, 1, n){
		cout << ans[i] << ' ';
	}
	cout << ans[n] << endl;
	return 0;
}