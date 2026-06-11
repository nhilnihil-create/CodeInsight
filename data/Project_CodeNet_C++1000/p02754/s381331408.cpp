#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define len(x) (int)(x.size())
#define all(vs) vs.begin(), vs.end()
using ii = pair<int, int>;
using ll = long long;

int32_t main(){
	ll n, a, b;
	cin >> n >> a >> b;
	ll k = n/(a+b);
	ll ans = k*a + min(a, n%(a+b));
	cout << ans << endl;	
}
