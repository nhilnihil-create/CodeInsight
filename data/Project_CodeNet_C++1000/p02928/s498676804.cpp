#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

const int MOD = 1000000007;

int main(){
	int n;
	ll k;
	cin >> n >> k;
	vector<int> a(n);
	rep(snip_i, n) cin >> a.at(snip_i);
	vector<int> a1(n, 0);
	vector<int> a2(n, 0);
	rep(i, n){
		rep(j, n){
			if(i < j){
				if(a.at(i) > a.at(j)) a1.at(i)++;
			}
			if(a.at(i) > a.at(j)) a2.at(i)++;
		}
	}
	ll ans = 0;
	rep(i, n){
		ans = (ans + (ll)a1.at(i) * k) % MOD;
		ll temp = (k * (k-1) / 2) % MOD;
		ans = (ans + (ll)a2.at(i) * temp) % MOD;
	}
	cout << ans << endl;
	return 0;
}