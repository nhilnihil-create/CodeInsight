#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
 
int main() {
	ll n, a,b;
	cin>>n>>a>>b;
	ll num_ab = n / (a+b);
	ll rem = n- num_ab * (a+b);
	ll ans = num_ab*a;
	if (rem >= a) ans += a;
	else ans += rem;
	cout << ans << endl;
	return 0;
}