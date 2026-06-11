#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <ios>
#include <ctype.h>
#include <stack>
#include <istream>
#include <stdio.h>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <functional>
#include <bitset>
#include <list>
#include <deque>
#include <time.h>
#include <random>
#include <iomanip>
#include <fstream>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b) for (int i = a; i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define pint pair<int,int>
#define SEG_LEN (1 << 20)
const int INF = 1000000007;
const long double EPS = 1e-15;
const long double PI = acos(-1);
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
using Graph_weighted = vector<vector<pair<int,int>>>;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
ll ceil(const ll a, const ll b) { return (a + b - 1) / b; }
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
// cout << a * modinv(b,INF) % INF << endl;
long long Modpow(long long n,long long m,long long mod){
  if(m == 0)return 1;
  if(m % 2)return (n * (Modpow(n,m - 1,mod) % mod)) % mod;
  long long tmp = Modpow(n,m / 2,mod);
  return tmp * tmp % mod;
}
ll Comb(ll a,ll b){
  ll ret = 1;
  REP(i,a - b + 1,a + 1){
    ret *= i;
    ret %= INF;
  }
  ll tmp = 1;
  REP(i,1,b + 1){
    tmp *= i;
    tmp %= INF;
  }
  return ret * modinv(tmp,INF) % INF;
}
int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  ll ans = Modpow(2,n,INF) - 1;
  ans -= Comb(n,a);
  if(ans < 0)ans += INF;
  ans -= Comb(n,b);
  if(ans < 0)ans += INF;
  cout << ans << endl;
  return 0;
}
 