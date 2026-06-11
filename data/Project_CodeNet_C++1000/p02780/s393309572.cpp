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

ll a[maxn];
int main()
{
  ios::sync_with_stdio(0);
  int n,k;
  cin >> n >> k;
  int j = 0;
  ll sum = 0;
  ll ans = 0;
  for(int i = 0 ; i < n ; i++)
  {
    cin >> a[i];
    sum += (a[i] + 1);
    if(i - j + 1 <= k)
      continue;
    sum -= (a[j] + 1);
    j++; 
    ans = max(ans, sum);
  }

  ans = max(ans, sum);

  cout << fixed << setprecision(6) <<  (ans/2.0) << endl;

  return 0;
}