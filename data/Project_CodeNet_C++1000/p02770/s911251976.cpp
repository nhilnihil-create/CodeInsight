#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int k, q;
ll d[5010];

ll solve(ll n, ll x, ll m){

  ll mx = x % m;

  vector<ll> sum_md_block(k+1);

  sum_md_block[0] = 0;

  rep(i, k){

    ll md = d[i] % m;
    if(md == 0) md = m;
    sum_md_block[i+1] = sum_md_block[i] + md;
  }

  ll sum_md = 0;
  sum_md = mx + sum_md_block[k] * ((n-1) / k) + sum_md_block[(n-1) % k];

  ll num_cross = sum_md / m;

  ll ret = (n-1) - num_cross;

  return ret;

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> k >> q;
  rep(i, k) cin >> d[i];

  vector<ll> ans(q);

  ll n, x, m;
  rep(i, q){
    cin >> n >> x >> m;
    ans[i] = solve(n, x, m);
  }

  rep(i, q){
    cout << ans[i] << endl;
  }

  

  return 0;
}
