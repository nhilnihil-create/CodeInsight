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
const ll mod = 998244353;

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

vector<ll> findDivs(ll n)
{
  vector<ll>divs;
  for(ll i = 1; i * i <= n ; i++)
  {
    if(n % i == 0)
    {
      ll x = n / i;
      if(i != 1)
        divs.push_back(i);
      if(x != i)
        divs.push_back(x);
    }
  }
  return divs;
}
ll solve(ll n)
{
  set<ll>ans;
  for(auto &c : findDivs(n - 1))
    ans.insert(c);
  for(auto &c : findDivs(n))
  {
    ll y = n;
    while(n % c == 0)
      n /= c;
    if(n % c == 1)
      ans.insert(c);
    n = y;
  }
  return ans.size();
}

int main()
{
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  cout << solve(n) << endl;
  
  return 0;
}