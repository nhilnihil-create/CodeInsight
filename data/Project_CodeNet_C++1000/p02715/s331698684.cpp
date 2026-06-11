  #include<bits/stdc++.h>
using namespace std;
using ll = long long;

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

const int maxn = 2e5 + 10;
ll fat[maxn], inv[maxn];

ll C(int n, int k)
{
  if(n < k) 
    return 0;
  if(n < 0 || k < 0) 
    return 0;
  return (((fat[n] * inv[k]) % mod) * inv[n - k]) % mod;
}

ll dp[maxn];

int main()
{
  fat[0] = 1;
  inv[0] = 1;
  for(int i = 1; i < maxn; i++)
  {
    fat[i] = (fat[i-1] * i) % mod;
    inv[i] = exp(fat[i], mod - 2);
  }

  ios::sync_with_stdio(0);
  ll n,k;
  cin >> n >> k;

  ll ans = 0;

  for(int i = k; i >= 1 ; i--)
  {
    ll p = (k / i);

    ll val = exp(p, n);
    for(int j = i + i; j <= k; j += i)
    {
      val = (val - dp[j] + mod) % mod;
    }
    dp[i] = val;
    dp[i] %= mod;
    ans = (ans +  (i * dp[i]) % mod) % mod;
  }

  cout << ans << endl;




  return 0;
}