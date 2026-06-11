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
	int n, m; cin >> n >> m;
	int ans = 0;
	if(n!=0){
		ans += n*(n-1)/2;
	}
	if(m!=0){
		ans += m*(m-1)/2;
	}
	cout << ans << endl;
	return 0;
}