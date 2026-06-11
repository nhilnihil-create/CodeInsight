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
ll LCM(ll x, ll y){
	return x/GCD(x, y)*y;
}

int main() {
	int n, m; cin >> n >> m;
	int s[10], c[10];
	vector<int> ans(n);
	rep(i, 0, n) ans[i] = 0;
	rep(i, 0, m){
		cin >> s[i] >> c[i];
		s[i]--;
	}
	rep(i, 0, m){
		if(s[i]==0 && c[i]==0 && n!=1){
			cout << -1 << endl;
			return 0;
		}
		rep(j, i+1, m){
			if(s[i]==s[j] && c[i]!=c[j]){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	rep(i, 0, m){
		ans[s[i]] = c[i];
	}
	if(n!=1 && ans[0]==0) ans[0] = 1;
	rep(i, 0, n) cout << ans[i];
	cout << endl;
	return 0;
}