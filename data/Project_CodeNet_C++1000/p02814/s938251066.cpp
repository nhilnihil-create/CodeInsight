#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define len(x) (int)(x.size())
#define all(vs) vs.begin(), vs.end()
using ii = pair<int, int>;
using ll = long long;

ll lcm(ll a, ll b){
	return a*b/__gcd(a, b); 
}
int32_t main(){
	ios::sync_with_stdio(0);
	int n; ll m;
	cin >> n >> m;
	vector<ll> vs(n);
	for(auto &x:vs) cin >> x;
	ll lm = vs[0];
	for(auto x:vs) lm = lcm(lm, x);
	ll ans = 0 ;
	for(auto x:vs){
		if(((lm/2)-x/2)%x!=0){
			cout << 0 << endl;
			return 0;
		}
	}
	ans = (m-(lm/2)+lm)/lm;
	cout << ans << endl;
}
