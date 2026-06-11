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

const int maxn = 1e3 + 5;
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
    fat[i] = (i * fat[i-1]) % mod;
    inv[i] = exp(fat[i], mod - 2);
  }
}

ll dp[maxn][(1 << 12) + 5];

int n,m;
int a[maxn], b[maxn];

ll solve(int pos, int mask)
{
  if(mask == (1 << n) - 1)
    return 0;
  if(pos == m)
    return INF;
  ll &ans = dp[pos][mask];
  if(ans != -1)
    return ans;
  ans = INF;
  ans = min(ans, solve(pos + 1, mask));
  ans = min(ans, solve(pos + 1, mask | b[pos]) + a[pos]);
  return ans;
}

int main()
{
  MSET(dp, -1);
  cin >> n >> m;
  for(int i = 0; i < m ; i++)
  {
    cin >> a[i];
    int qt;
    cin >> qt;
    for(int j = 0 ; j < qt; j++)
    {
      int c;
      cin >> c;
      c--;
      b[i] |= (1 << c);
    }
  }

  auto ans = solve(0,0);
  if(ans == INF)
    ans = -1;
  cout << ans << endl;
  return 0;
}