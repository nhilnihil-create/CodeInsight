#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define siz(v) (ll)(v).size()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, x, n) for (ll i = x; i < (ll)(n); i++)
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const ll mod = 1000000007;
const ll INF = 100000000000000099;
vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
//cin.tie(0);
//ios::sync_with_stdio(false);

ll dp[200020][2] = {};

const ll MAX = 200030;//設定して

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;//＊１
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}


signed main()
{
  COMinit();
  
  ll n;
  cin >> n;
  string s;
  cin >> s;

  dp[0][0] = 1;

  ll nofk = 0;

  for (int i = 1; i <= 2*n; i++)
  {

    if (s.at(i - 1) == 'B') //odd
    {
      dp[i][0] = 0;

      if (nofk%2==0)
      { //前偶数
        dp[i][1] = dp[i - 1][1]+dp[i-1][0];
        nofk++;
      }
      else
      {
        dp[i][1] = ((dp[i - 1][1]+dp[i-1][0])%mod) * nofk;
        nofk--;
      }
    }
    else //even
    {
      dp[i][1] = 0;

      if (nofk%2==1)
      { 
        dp[i][0] = dp[i - 1][1]+dp[i-1][0];
        nofk++;
      }
      else{
        dp[i][0] = ((dp[i - 1][1]+dp[i-1][0])%mod) * nofk;
        nofk--;

      }
    }

    dp[i][0]%=mod;
    dp[i][1]%=mod;
    //cout<<i<<":"<<dp[i][0]<<":"<<dp[i][1]<<":"<<nofk<<endl;

    if(nofk<0 || (nofk!=0 && i==2*n)){
      cout<<0<<endl;
      return 0;
    }
  }

  cout << ((dp[2 * n][1]%mod)*(fac[n]%mod))%mod << endl;
}