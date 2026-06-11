#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<ll>>;
using P = pair<int,int>;

#define MOD 1000000007
#define INF 1000000
#define PI 3.14159265358979323846264338327950L
#define MAX 200010
#define lb lower_bound //[2,4)=lb(4)-lb(2);

#define REP(i,n) for(int i=0;i<n;++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl

/*
合計N個のボール
K個の青い、N-K個の赤いボール
*/

vector<ll> fac(MAX);

void COMinit()
{
  fac[0]=1;
  for (ll i=1;i<=MAX;i++)
  {
    fac[i]=(fac[i-1]*i) % MOD; 
  }
}

ll fast(ll a, ll n)
{
  ll ret=1;
  while (n>0)
  {
    if (n & 1)
    {
      ret = (ret * a) % MOD;
    }
    n = (n>>1);
    a = a * a % MOD;
  }
  return (ret);
}

ll comb(ll n, ll r)
{
  ll top=1;
  ll bot=1;
  ll ans;

  if (n<r || n<0 || r<0) return (0);

  top = fac[n];
  bot = fac[r]*fac[n-r] % MOD;
  ans = top * fast(bot,MOD-2) % MOD;
  return (ans);
}

int main()
{
  ll N,K;cin>>N>>K;
  ll red = N-K;
  ll blue = K;
  
  COMinit();
  
  for (int i=1;i<=K;i++)
  {
    ll ans = comb(red+1,i) % MOD;
    ans *= comb(blue-1,i-1);
    ans %= MOD;
    cout<<ans<<endl;
  }
}