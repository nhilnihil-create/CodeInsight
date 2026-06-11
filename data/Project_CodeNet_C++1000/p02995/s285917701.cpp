#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    ll g = gcd(a, b);
    return a / g * b;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	--a;
	ll ac = a / c;
	ll ad = a / d;
	ll acd = a / lcm(c, d);
	ll bc = b / c;
	ll bd = b / d;
	ll bcd = b / lcm(c, d);
	ll ans = (b - bc - bd + bcd) - (a - ac - ad + acd);
	cout << ans << endl;
	return 0;
}
