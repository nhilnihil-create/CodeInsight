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

map<ll, ll>mapa;

int main()
{
  ios::sync_with_stdio(false);
  int n,p;
  cin >> n >> p;
  string s;
  cin >> s;
  
  ll ans = 0;
  if(p == 2 || p == 5)
  {
    for(int i = 0; i < n ; i++)
    {
      if((s[i] - '0') % p == 0)
        ans += i + 1;
    }
    cout << ans << endl;
    return 0;
  }

  ll sum = 0;
  ll d = 1;
  for(int i = n-1 ; i >= 0 ; i--)
  {
    sum = ((s[i] - '0') * d + sum) % p ;
    d = (d * 10) % p;
    mapa[sum]++;
  }

  ans = mapa[0];

  for(const auto &x : mapa)
  {
    ans += (x.second * (x.second - 1)) / 2;
  }

  cout << ans << endl;

  return 0;
}