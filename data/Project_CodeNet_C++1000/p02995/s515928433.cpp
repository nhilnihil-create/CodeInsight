#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

ll gcd(ll a, ll b) {
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

ll lcm(ll a, ll b){
   return a*b/gcd(a, b);
}

int main(){
	ll A, B, C, D;
	cin >> A >> B >> C >> D;

	ll E = lcm(C,D);
	ll ans = B - B/C - B/D + B/E;
	A--;
	ans -= A - A/C - A/D + A/E;
	cout << ans << endl;
	return 0;
}
