//compiledef
#include <bits/stdc++.h>
#define rep(i, n) for(i=0;i<(n);i++)
#define per(i, n) for(i=(n);i>0;i--)
#define repx(i, n, x) for(i=(x);i<(n);i++)
#define xper(i, n, x) for(i=(n);i>(x);i--)
#define pback push_back

//c++def
using namespace std;
typedef long long int ll;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;

int main(){
	ll a, b, c;
	ll ans;
	cin >> a >> b >> c;

	ans = c - a - b;
	if(ans*ans > 4*a*b && ans > 0)cout << "Yes" << endl;
	else cout << "No" << endl;
}
