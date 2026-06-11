#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,w,h,i,j,k,l,m,n,q,x,y,z,t,u,v;
	ll		ans = 0;
	string	s;
	cin >> n >> q;
	//vector<ll>	aa(n);
	//for(i=0;i<n;i++) cin >> aa[i];
	//vector<ll>	dp(n+1,INFL);
	//vector<vector<ll>>	dp2(x , vector<ll>(y,INFL));
	dsu d(n);
	for(i=0;i<q;i++) {
		cin >> t >> u >> v;
		if (t==0) {
			d.merge(u,v);
		} else {
			if (d.same(u,v)) {
				cout << 1 << endl;
			} else {
				cout << 0 << endl;
			}
		}
	}
	//cout << ans << endl;
	return 0;
}
