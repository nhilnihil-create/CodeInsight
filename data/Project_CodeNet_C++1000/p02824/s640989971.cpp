#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

bool fanc(int mid, vector<int> &a, int n, int m, int v, int p){
	vector<int> ot;
	if(mid < p) return true;
	rep(i, n){
		if(i == mid) continue;
		ot.push_back(a.at(i));
	}
	ll now = a.at(mid);
	now += m;
	if(now < ot.at(p-1)) return false;
	ll add = (ll)m * (v-1);
	rep(i, n-1){
		if(i < p-1) add -= m;
		else{
			add -= min((ll)m, now - ot.at(i));
		}
	}
	// cerr << "t " << mid << " " << add << " " << now << endl;
	if(add > 0) return false;
	else return true;
}

int main(){
	int n, m, v, p;
	cin >> n >> m >> v >> p;
	vector<int> a(n);
	rep(snip_i, n) cin >> a.at(snip_i);
	sort(a.begin(), a.end(), greater<int>());
	vector<ll> sum(n+1, 0);
	rep(i, n) sum.at(i+1) = sum.at(i) + a.at(i);
	int ok = 0, ng = n;
	while(ng - ok > 1){
		int mid = (ok+ng)/2;
		if(fanc(mid, a, n, m, v, p)) ok = mid;
		else ng = mid;
	}
	cout << ok+1 << endl;
	return 0;
}