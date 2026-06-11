#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

int main(){
	ll n; cin >> n;
	ll ans = 0;
	for( ll a = 1; a <= n; ++a ){
		ll b = n/a;
		ll c = n - a*b;
		if( c == 0 ){
			b -= 1;
		}
		ans += b;
	}
	cout << ans << endl;
}