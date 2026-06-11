#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 100100;
ll w[MN];
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	ll n,m,v,p;
	cin >> n >> m >> v >> p;
	for(int i=0;i<n;i++) {
		cin >> w[i];
	}
	sort(w,w+n);
	ll st = 0,ed = n-1;
	ll ls = n-1;
	while(st <= ed) {
		ll md = (st+ed)/2;
		ll go = w[md]+m;
		ll sm = 0;
		for(int i=0;i<n;i++) {
			ll val = min(go-w[i],m);
			if(i > n-p) {
				val = m;
			}
			val = max(val,0LL);
			sm += val;
		}
		if(sm >= m*v && w[md]+m >= w[n-p]) {
			ed = md-1;
			ls = md;
		} else {
			st = md+1;
		}
	}
	cout << n-ls << '\n';
}
