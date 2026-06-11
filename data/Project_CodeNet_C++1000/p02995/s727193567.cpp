#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}



int main(){
	ll a,b,c,d;
	cin >> a >> b >> c >> d;

	ll l = lcm(c,d);
	ll ans = (b-(b/c)-(b/d)+(b/l)) - (a-(a/c)-(a/d)+(a/l));
	if (a%c!=0 && a%d!=0) ans++;
	cout << ans << endl;
	
	return 0;
}