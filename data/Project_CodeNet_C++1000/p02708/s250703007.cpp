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

int main()
{
  ios::sync_with_stdio(0);
  int n,k;
  cin >> n >> k;

  ll ans = 0;
  for(ll i = k; i <= n + 1 ; i++)
  {
    ll mi = (i * (i - 1)) / 2;
    ll ma = n * i - mi;
    ans += ma - mi + 1; 
    ans %= mod;
  }

  cout << ans << endl;

  return 0;
}