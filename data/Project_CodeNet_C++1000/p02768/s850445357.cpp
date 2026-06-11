#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

template <typename T>
bool chmax(T &a, T &b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T>
bool chmin(T &a, T &b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}






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

ll RepeatedSquaring(ll N, ll P, ll M) {
  if(P==0) return 1;
  if(P%2==0) {
    ll t = RepeatedSquaring(N, P/2, M);
    return t*t % M;
  }
  return N*RepeatedSquaring(N, P-1, M)%M;
}



ll modre(ll num) {
  num %= MOD;
  if(num < 0) num += MOD;
  return num;
}

ll mod_pow(ll x,ll n) {
	if (n == 0) return 1;
	ll res = mod_pow(x*x % mod, n / 2);
	if (n & 1) res = res * x % mod;
	return res;
}
 

 
ll comb(ll n, ll x) {
	ll ret = 1,k=1;
	rep(i,x)ret = (ret * (n - i))%mod;
	rep(i,x)k = (k * (x-i))%mod;
	// k = RepeatedSquaring(k, MOD-2, MOD);
	k = mod_pow(k, mod - 2);
	ret = (ret*k + mod) % mod;
	return ret;
}
  
int main() {
  ll a,b,n;
  cin >> n >> a >> b;
  ll ans = RepeatedSquaring(2, n, MOD) - 1;
  a = comb(n,a);
  b = comb(n,b);
  cout << modre(ans - a - b) << endl;
}




