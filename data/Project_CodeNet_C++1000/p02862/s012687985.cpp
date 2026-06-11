#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
#include <numeric>
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define CST(x) cout<<fixed<<setprecision(x)//小数点以下の桁数指定
#define ct(a) cout<<a<<endl
static const double pi = 3.141592653589793;
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e9+7;
const ll mod= 1e9 + 7;

vector<ll> K(3000001);

ll mod_pow(ll x, ll n) {
	if (n == 0) return 1;
	ll res = mod_pow(x*x % mod, n / 2);
	if (n & 1) res = res * x % mod;
	return res;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	K[0] = 1;
	FOR(i, 1, 3000001)K[i] = (K[i-1] * i) % mod;

	ll X, Y,ans;
	cin >> X >> Y;
	ll A = 2 * X - Y, B = 2 * Y - X;
	if (A < 0 || A % 3 != 0)cout << 0 << endl;
	else if (B < 0 || B % 3 != 0)cout << 0 << endl;
	else {
		A /= 3; B /= 3;
		cout << (K[A+B]*mod_pow((K[A]*K[B])%mod,mod-2))%mod << endl;
	}
	

	return 0;
}