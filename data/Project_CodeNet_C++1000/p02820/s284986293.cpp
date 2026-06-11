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
  int ans = 0;
  map<char, int>vals;
  vals['r'] = r;
  vals['s'] = s;
  vals['p'] = p;
  vector<bool>win(n, false);
  for(int i = n - 1 ; i >= 0; i--)
  {
    int next = i + k;
    if(next < n)
    {
      if(t[i] == t[next] && win[next])
        continue;
    }
    win[i] = true;
    ans += vals[f(t[i])];
  }
  cout << ans << endl;
  return 0;
}