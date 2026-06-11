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
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i>b;i--)
#define vint vector<int> 
#define vvint vector<vint>
#define CST(x) cout<<fixed<<setprecision(x)//小数点以下の桁数指定
#define ct(a) cout<<a<<endl
static const double pi = 3.141592653589793;
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int INF = 1e9+7;
const int mod= 1e9 + 7;

ll mod_pow(ll x, ll n) {
	if (n == 0) return 1;
	ll res = mod_pow(x*x % mod, n / 2);
	if (n & 1) res = res * x % mod;
	return res;
}

ll comb(ll n, ll x) {
	ll ret = 1, k = 1;
	FOR(i, 0, x)ret = (ret * (n - i)) % mod;
	FOR(i, 1, x + 1)k = (k*i + mod) % mod;
	k = mod_pow(k, mod - 2);
	ret = (ret*k + mod) % mod;
	return ret;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	ll N,A,B;
	cin >> N>>A>>B;
	
	ll ans = 1;

	ans = mod_pow(2LL, N);

	ll a = comb(N,A);
	ll b = comb(N, B);
	
	cout << (ans-a-b+2*mod-1)%mod << endl;

	return 0;
}
