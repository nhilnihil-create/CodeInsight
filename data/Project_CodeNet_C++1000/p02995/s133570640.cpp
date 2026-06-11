#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

ll gcd(ll a, ll b){
	return b ? gcd(b, a%b) : a;
}

ll lcm(ll c, ll d){
	return c*d/gcd(c, d);
}

ll f(ll x, ll c, ll d){
	ll ans = x;
	ans -= x/c;
	ans -= x/d;
	ans += x/lcm(c, d);

	return ans;
}

int main(){
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll ans = f(b, c, d) - f(a-1, c, d);
	
	cout << ans << endl;
	return 0;
}
