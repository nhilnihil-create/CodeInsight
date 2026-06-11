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



int main()
{
  ios::sync_with_stdio(false);
  int a,b,c,x,y;
  cin >> x >> y >> a >> b >> c;
  vector<ll>p(a), q(b), r(c);

  for(int i = 0; i < a; i++)
  {
    cin >> p[i];
  }

  for(int i = 0; i < b; i++)
  {
    cin >> q[i];
  }

  for(int i = 0; i < c; i++)
  {
    cin >> r[i];
  }

  sort(all(p), greater<ll>());
  sort(all(q), greater<ll>());
  sort(all(r), greater<ll>());

  while(p.size() > x)
    p.pop_back();


  while(q.size() > y)
    q.pop_back();


  vector<ll>d(all(p));

  d.insert(d.end(), all(q));
  d.insert(d.end(), all(r));


  sort(d.begin(), d.end(), greater<ll>());

  ll ans = accumulate(d.begin(), d.begin() + x + y , 0LL);

  cout << ans << endl;


  return 0;
}