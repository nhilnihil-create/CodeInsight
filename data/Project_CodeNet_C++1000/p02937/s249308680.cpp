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

set<ll>q[26];

int main()
{
  ios::sync_with_stdio(0);
  string s;
  string t;
  cin >> s >> t;
 
  for(int i = 0 ; i < s.size(); i++)
  {
    q[s[i] - 'a'].insert(i + 1);
  }

  int last = 0;
  ll cnt = 0;
  for(int i = 0 ; i < t.size(); i++)
  {
    int val = t[i] - 'a';
    if(q[val].size() == 0)
    {
      cout << "-1\n";
      return 0;
    }
    auto it = q[val].lower_bound(last + 1);
    if(it == q[val].end())
    {
      cnt++;
      last = *q[val].begin();
    }
    else
    {
      last = *it;
    }
  }
  cout << (cnt * s.size() + last) << endl;
  return 0;
}