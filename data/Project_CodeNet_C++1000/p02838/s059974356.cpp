#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define debug(x) cerr << #x << " = " << x << endl;
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

ll a[maxn];

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

ll qt[70];


int main()
{

  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n ; i++)
  {
    ll x;
    cin >> x;
    for(int j = 0; j < 61; j++)
    {
      qt[j] += bool(x & (1LL << j));
    } 
  }

  ll ans = 0;


  for(int i = 0; i < 61; i++)
  {
    // debug(i);
    // debug(qt[i]);
    // cout << "\n\n\n";
    ll x = (1LL << i) % mod;
    ll y = (qt[i] * (n - qt[i])) % mod;
    ans += ( x * y) % mod;
    ans %= mod;
  }

  cout << ans << endl;

  return 0;
}