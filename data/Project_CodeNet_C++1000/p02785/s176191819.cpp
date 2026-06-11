#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define rev(v) reverse(v.begin(), v.end());
#define io() ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);srand(time(NULL));
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
	io();
	int n, k; cin >> n >> k;
	vector<ll> v(n);
	for(auto &x : v) cin >> x;
	sort(allr(v));
	ll ans = 0;
	for(int i = k;  i < n; ++i){
		ans += v[i];
	}
	cout << ans << '\n';
	return 0;
}