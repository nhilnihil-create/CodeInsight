#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define debug(x) cerr << #x << " = " << x << endl;
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

int a[maxn];

int main()
{
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int sum = 0;
  for(int i = 0 ; i < n ; i++)
  {
    cin >> a[i];
    if( i & 1)
      sum -= a[i];
    else
      sum += a[i];
  }
  int x1 = sum;
  cout << x1 << ' ';
  for(int i = 1; i < n; i++)
  {
    int val = 2*a[i-1] - x1;
    cout << val << ' ';
    x1 = val; 
  }

  cout << endl;



  return 0;
}