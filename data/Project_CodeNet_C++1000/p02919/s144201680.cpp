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
const ll mod = 961748941;

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

const int maxn = 2e5  + 5;
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

int l[maxn], r[maxn], pos[maxn];
int a[maxn];

int main()
{
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++)
  {
    cin >> a[i];
    pos[a[i]] = i;
  }
  multiset<ll>s;
  s.insert(0);
  s.insert(0);
  s.insert(n+1);
  s.insert(n+1);
  // a < b < pos[i] < c < d
  ll ans = 0;
  for(ll i = n; i >= 1; i--)
  {
    auto it = s.lower_bound(pos[i]);
    --it;
    --it;
    auto a = *it;
    it++;
    auto b = *it;
    it++;
    auto c = *it;
    it++;
    auto d = *it;
    s.insert(pos[i]);
    ans += ((b - a) * (c - pos[i]) + (d - c) * (pos[i] - b)) * i;
  }

  cout << ans << endl;

  return 0;
}