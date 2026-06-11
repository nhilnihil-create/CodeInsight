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

const int maxn = 2505 + 5;
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
int n,k;
int a[maxn];

bool test(int x)
{
  vector<int>v;
  for(int i = 0; i < n; i++)
  {
    v.push_back(a[i] % x);
  }

  sort(v.begin(), v.end());
  int l = 0;
  int r = v.size() - 1;
  int sum = 0;
  int rq = 0;
  while( l <= r )
  {
    if(sum <= 0)
    {
      rq += v[l];
      sum += v[l];
      l++;
    }
    else
    {
      rq += (x - v[r]);
      sum -= (x - v[r]);
      r--;
    }
  }
  if( sum != 0 || rq > 2 * k)
    return false;
  return true;
}

int main()
{
  cin >> n >> k;
  int sum = 0;
  for(int i = 0 ; i < n ; i++)
  {
    cin >> a[i];
    sum += a[i];
  }
  ll ans = 0;
  for(ll i = 1; i * i <= sum ; i++)
  {
    if(sum % i == 0)
    {
      if(test(i))
        ans = max(ans, i);
      if(test(sum / i))
        ans = max(ans, sum / i);
    }
  }
  cout << ans << endl;
  return 0;
}