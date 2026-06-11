#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define rREP(i,m,n) for(ll i = (m); i >= (n); i--)
#define ALL(c) (c).begin(), (c).end()
#define print(x) cout << (x) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;

template< typename T >
T mod_pow(T x, T n, const T &p) {
  T ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= p;
    (x *= x) %= p;
    n >>= 1;
  }
  return ret;
}

template< typename T>
T mod_add(T a, T b, const T &p)
{
  a%=p;
  b%=p;
  return (a+b+p)%p;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,k;
    cin >> n >> k;

    ll ans_ary[k+1];
    rep(i,k+1) ans_ary[i] = 0;

    for (ll i=k;i>0;i--)
    {
      ans_ary[i] = mod_pow(k/i,n,MOD);
      if (i*2<=k)
      {
        ll tmpn = 2;
        while(i*tmpn<=k)
        {
          ans_ary[i] -= ans_ary[i*tmpn];
          tmpn++;
        }
      }
    }
    ll ans = 0;
    rep(i,k)
    {
      ans = mod_add(ans, ans_ary[i+1]*(i+1), MOD);
      // cout << ans_ary[i+1] << " ";
    }
    // cout << endl;
    cout << ans << endl;
}