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

ll lcm(ll a, ll b)
{
  return a * (b / __gcd(a,b));
}

char f(char c)
{
  if(c == 'r')
    return 'p';
  else if(c == 'p')
    return 's';
  else
    return 'r';
}

int main()
{

  ios::sync_with_stdio(0);
  int n,k,r,s,p;
  string t;
  cin >> n >> k >> r >> s >> p;
  cin >> t;
  map<char,int>vals;
  vals['r'] = r;
  vals['s'] = s;
  vals['p'] = p;
  string history;
  int res = 0;
  for(int i = 0; i < k; i++)
    history += 'a';
  for(int i = 0; i < n ; i++)
  {
    char x = f(t[i]);
    if(i - k >= 0)
    {
      char y = history[i % k];
      if(y != x)
      {
        history[i % k] = x;
        res += vals[x];
      }
      else
        history[i % k] = 'a';
    }
    else
    {
      res += vals[x];
      history[i % k] = x;
    }
  }
  cout << res << endl;
  return 0;
}