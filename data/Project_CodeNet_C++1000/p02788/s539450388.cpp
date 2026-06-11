#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	int n, d, a;
	cin >> n >> d >> a;
	vector<pair<int, int>> vp(n);
	rep(i, n){
		int x, h;
		cin >> x >> h;
		vp.at(i) = make_pair(x, h);
	}
	sort(vp.begin(), vp.end());
	vector<ll> za;
	vector<ll> co;
	ll ans = 0;
	rep(i, n){
		ll x, h;
		tie(x, h) = vp.at(i);
		int n = lower_bound(za.begin(), za.end(), x) - za.begin();
		ll atkc = 0;
		if(co.size() != 0) atkc = co.back();
		if(n != 0) atkc -= co.at(n-1);
		h -= (ll)atkc * a;
		if(h <= 0) continue;
		ll ac = (h+a-1)/a;
		ans += ac;
		za.push_back((ll)x+2*d);
		if(co.size() != 0)ac += co.back();
		co.push_back(ac);
	}
	cout << ans << endl;
	return 0;
}