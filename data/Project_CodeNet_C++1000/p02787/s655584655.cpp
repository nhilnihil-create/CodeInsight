  #include<bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include<debug.h>
#else
#define db(...) 21
#endif

#define debug(x) cout << #x << " = " << x << endl;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define FOR(it, b, e) for (typeof(b) it = (b); it != (e); ++it)
#define MSET(c, v) memset(c, v, sizeof(c))

const int INF = 0x3F3F3F3F; 
const int NEGINF = 0xC0C0C0C0;
const int NULO = -1;
const double EPS = 1e-10;
const ll mod = 1e9 + 7;

inline int cmp(double x, double y = 0) 
{  
  if(fabs(x - y) < EPS)
    return 0;
  return x > y ? 1 : -1;
}

ll exp(ll a, ll b)
{
  ll ans = 1;
  while(b)
  {
    if(b & 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}

const int maxn = 2e3 + 10;
ll fat[maxn], inv[maxn];

ll C(int n, int k)
{
  if(n < k) 
    return 0;
  if(n < 0 || k < 0) 
    return 0;
  return (((fat[n] * inv[k]) % mod) * inv[n - k]) % mod;
}

void initFactorials()
{
  fat[0] = 1;
  inv[0] = 1;
  for(int i = 1; i < maxn; i++)
  {
    fat[i] = (fat[i-1] * i) % mod;
    inv[i] = exp(fat[i], mod - 2);
  }
}

ll dp[maxn][10005];

int a[maxn], b[maxn];

int main()
{
  ios::sync_with_stdio(false);
  MSET(dp, INF);
  int h,n;
  cin >> h >> n;
  for(int i = 0; i < n ; i++)
  {
    cin >> a[i] >> b[i];
  }


  dp[0][0] = 0;
  for(int i = 0; i < n ; i++)
  {
    for(int j = 0; j <= h; j++)
    {
      dp[i+1][j] = dp[i][j];
      dp[i][min(h, j + a[i])] = min(dp[i][min(h, j + a[i])], dp[i][j] + b[i]);
      dp[i + 1][min(h, j + a[i])] = min(dp[i + 1][min(h, j + a[i])], dp[i][j] + b[i]);
    }
  }

  cout << dp[n][h] << endl;

  return 0;
}