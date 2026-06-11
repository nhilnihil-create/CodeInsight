#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i = 0; i < n; i++)
#define per(i,n) for(ll i = n-1; i >= 0; i--)
#define REP(i,n) for(ll i = 1; i < n; i++)
#define PER(i,n) for(ll i = n; i >= 1; i--)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
using vs = vector<string>;
using vb = vector<bool>;
using vc = vector<char>;
using vcc = vector<vc>;
using vP = vector<P>;
using vPP = vector<vP>;
using vPl = vector<Pl>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll mod = 1e9+7;

long long Modpow(long long a, int n){
  if(n == 0) return 1;
  if(n%2 == 0){
    long long res = Modpow(a, n/2);
    return res * res % mod;
  }
  return a * Modpow(a, n-1) % mod;
}

int inv(int n) { // 逆元
  return Modpow(n, mod-2);
}

struct Combination { 
  vector<long long> fact, ifact;
  Combination(int n):fact(n+1), ifact(n+1) {
    fact[0] = 1;
    for(long long i = 1; i <= n; i++) fact[i] = fact[i-1]*i % mod;
    ifact[n] = inv(fact[n]);
    for(long long i = n; i >= 1; i--) ifact[i-1] = ifact[i]*i % mod;
  }
  long long operator()(int n, int k) { // modcom (nCk % mod)
    if(k < 0 || k > n) return 0;
    return ((fact[n] * ifact[k]) % mod * ifact[n-k]) % mod;
  }
};

int main(){
  ll n, k;
  cin >> n >> k;
  Combination c(n);
  for(ll i = 1; i <= k; i++) {
    ll ans = (c(n-k+1, i) % mod) * c(k-1, i-1) % mod;
    cout << ans << endl;
  }
}