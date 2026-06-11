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

const int maxn = 5e3 + 5;
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

struct Hash
{
  const ll mod1 = 1e9 + 7;
  const ll mod2 = 100001347; 
  const ll P1 = 547;
  const ll P2 = 769;
  string s;
  ll pre1[maxn];
  ll pre2[maxn];
  ll poww1[maxn];
  ll poww2[maxn];
  Hash(string s) : s(s){}
  Hash(){}
  void init()
  {
    poww1[0] = 1;
    poww2[0] = 1;
    for(int i = 1 ; i < maxn ; i++)
    {
      poww1[i] = (poww1[i - 1] * P1) % mod1;
      poww2[i] = (poww2[i - 1] * P2) % mod2;
    }

    for(int i = 0; i < s.size(); i++)
    {
      pre1[i + 1] = ((pre1[i] * P1) + s[i] - 'a' + 1) % mod1;
      pre2[i + 1] = ((pre2[i] * P2) + s[i] - 'a' + 1) % mod2;
    }
  }

  pair<ll,ll> substr(int l, int r)
  {
    ll x = (pre1[r] - (pre1[l - 1] * poww1[r - l + 1]) % mod1 + mod1) % mod1;
    ll y = (pre2[r] - (pre2[l - 1] * poww2[r - l + 1]) % mod2 + mod2) % mod2;
    return {x,y};
  }

} h;

map<pair<ll, ll>, int>mapa;
int n;
bool check(int mid)
{
  mapa.clear();
  for(int i = 0 ; i < n ; i++)
  {
    int j = i + mid - 1;
    if(j >= n)
      break;
    auto H = h.substr(i+1,j+1);
    if(mapa.count(H) == 0)
      mapa[H] = j;
    else if(mapa[H] < i)
      return true;
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(0);
  
  cin >> n;
  string s;
  cin >> s;
  h.s = s;
  h.init();

  int lo = 0; 
  int hi = n;

  int ans = 0;
  while(lo <= hi)
  {
    int mid = (lo + hi) >> 1;
    if(check(mid))
    {
      ans = mid;
      lo = mid + 1;
    }
    else
    {
      hi = mid - 1; 
    }
  }

  cout << ans << endl;

  return 0;
}