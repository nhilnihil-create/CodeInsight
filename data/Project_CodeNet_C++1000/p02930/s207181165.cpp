#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <numeric>
#include <bitset>
#include <cmath>

using namespace std;
using ll = long long;
using ld = long double;
const ll mod =  998244353 ;
const ll inf = 1e18;

#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REP_FROM(i, j, n) for (ll i = (j); i < (n); ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())

template<typename T> void print_vec(vector<T> a) {int n = a.size();REP(i, n) {cout >> a[i]; if(i!=n-1) cout << " "; else cout << endl;}}
ll power(ll base, ll exponent){ if(exponent % 2){ return power(base, exponent - 1) * base % mod; }else if(exponent){ ll root_ans = power(base, exponent / 2); return root_ans * root_ans % mod; }else{ return 1; }}
ll inverse(ll x){ return power(x, mod - 2);}
ll gcd(ll a, ll b) {if(a < b) gcd(b, a);ll r;while(r=a%b) {a=b;b=r;}return b;}
template<typename T> ll sum(T begin, T end) {return accumulate(begin, end, 0ll);}
struct combination{ vector<ll> fact, inv; combination(int sz) : fact(sz + 1), inv(sz + 1){ fact[0] = 1; for(int i = 1; i <= sz; i++){ fact[i] = fact[i - 1] * i % mod; } inv[sz] = power(fact[sz], mod - 2); for(int i = sz - 1; i >= 0; i--){ inv[i] = inv[i + 1] * (i + 1) % mod; } } ll C(int p, int q) const{ if(q < 0 || p < q) return 0; return (fact[p] * inv[q] % mod * inv[p - q] % mod); } };

int bsearch(const vector<ll>& a, ll x){
  int lft = 0;
  int rgt = a.size();
  while (rgt - lft > 1) {
    int mid = (lft + rgt) / 2;
    if(a[mid] < x) {
      lft = mid;
    }
    else {
      rgt = mid;
    }
  }
  return lft;
}
signed main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int bit_length = ceil(log2(n));
  vector<vector<ll>> g(n ,vector<ll>(n));
  REP(k, bit_length) {
    int bit = 1 << k;
    REP(i, n) {
      REP_FROM(j, i+1, n) {
        if((i & bit) != (j & bit)) {
          g[i][j] = k + 1;
        }
      }
    }
  }
  REP(i, n) {
    REP_FROM(j, i+1, n) {
      cout << g[i][j] << " ";
    }
    cout << endl;
  }
  return 0; 
}
