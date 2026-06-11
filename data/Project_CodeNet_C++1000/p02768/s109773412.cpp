#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define debug(x) (cerr << #x << " = " << x << endl;)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define FOR(it, b, e) for (typeof(b) it = (b); it != (e); ++it)
#define MSET(c, v) memset(c, v, sizeof(c))

const int INF = 0x3F3F3F3F; 
const int NEGINF = 0xC0C0C0C0;
const int NULO = -1;
const ll mod = 1e9 + 7;
const double EPS = 1e-10;

inline int cmp(double x, double y = 0) 
{  
  if(fabs(x - y) < EPS)
    return 0;
  return x > y ? 1 : -1;
}

const int maxn = 2e5 + 100;


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

ll fat[maxn], inv[maxn];

ll C(int n, int k)
{
  ll ans = 1;
  for(int i = 1; i <= k; i++)
  {
    ans = (ans * n) % mod;
    n--;
  }
  ans = (ans * inv[k]) % mod;
  return ans;
}


int main()
{
  inv[0] = fat[0] = 1;
  for(int i = 1; i < maxn ; i++)
  {
    fat[i] = (fat[i-1] * i) % mod;
    inv[i] = exp(fat[i], mod-2);
  }
  ios::sync_with_stdio(0);
  int n,a,b;
  cin >> n >> a >> b;

  auto ans = (exp(2, n) - 1 + mod) % mod;
  auto val = (C(n, a) + C(n, b)) % mod;
  ans = (ans - val + mod) % mod;
  cout << ans << endl;
  return 0;
}