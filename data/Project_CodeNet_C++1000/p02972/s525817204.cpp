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

int a[maxn], v[maxn];

int main()
{
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  
  for(int i = 1 ; i <= n ; i++)
  {
    cin >> a[i];
  } 
  vector<int>ans;
  for(int i = n ; i >= 1 ; i--)
  {
    int sum = 0;
    for(int j = i; j <= n; j += i)
      sum += v[j];
    if(sum % 2 != a[i])
    {
      v[i] = 1;
      sum++;
    }
    if(v[i])
      ans.push_back(i);
  }
  cout << ans.size() << endl;
  for(const auto &c : ans)
    cout << c << ' ';
  cout << endl;

  return 0;
}