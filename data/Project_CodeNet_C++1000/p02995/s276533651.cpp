#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

ll gcd(ll a, ll b){
	if(0 < b) return gcd(b, a%b);
	else return a;
//	return b ? gcd(b, a%b) : a;
}

ll lcm(ll a, ll b){
	return a*b/gcd(a,b);
}

ll f(ll a, ll b, ll c){
	ll ans = a;
	ans -= a/b;
	ans -= a/c;
	ans += a/lcm(b,c);
	return ans;
}

int main(){
	ll a,b,c,d;
	cin >> a >> b >> c >> d;

	ll ans = f(b,c,d) - f(a-1,c,d);
	cout << ans << endl;
	return 0;
}