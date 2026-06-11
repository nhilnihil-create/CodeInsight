#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f40;
const long long mod=2e9+7;
const long double PI = acos(0);
// }}} End Header
int main() {
	ll a, b;
	cin >> a >> b;
	cout << (a*b)/__gcd(a, b) << endl;
	return 0;
}
