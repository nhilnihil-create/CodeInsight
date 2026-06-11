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

const int maxn = 3e5 + 5;
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

ll f[maxn], a[maxn], c[maxn], d[maxn];
int n;

bool check(ll val, ll k)
{
  bool ok = true;
  for(int i = 0; i < n ; i++)
  {
    if(f[i] * a[i] > val)
    {
      ll qt = val / f[i];
      ll b = min(k, a[i] - qt);
      a[i] -= b;
      k -= b;
    }
    ok &= f[i] * a[i] <= val;
  }
  return ok;
}

int main()
{
  ios::sync_with_stdio(false);
  ll k;
  cin >> n >> k;
  
  for(int i = 0; i < n ; i++)
  {
    cin >> a[i];
    c[i] = a[i];
  }
  for(int i = 0; i < n ; i++)
  {
    cin >> f[i];
    d[i] = f[i];
  }

  sort(c, c + n, greater<ll>());
  sort(d, d + n);
  
  
  ll lo = 0;
  ll hi = 1e17 + 5;
  ll ans = -1;

  while(lo <= hi)
  {
    ll mid = (lo + hi) >> 1;
    
    for(int i = 0; i < n ; i++)
    {
      a[i] = c[i];
      f[i] = d[i];
    }

    if(check(mid, k))
    {
      ans = mid;
      hi = mid - 1;
    }
    else
    {
      lo = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}