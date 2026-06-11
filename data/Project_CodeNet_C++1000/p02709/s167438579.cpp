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

const int maxn = 2000 + 10;

ll a[maxn];

ll dp[maxn][maxn];

int main()
{

  MSET(dp, 0);

  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  
  vector<pair<ll, int> >ord;

  for(int i = 0; i < n ; i++)
  {
    cin >> a[i];
    ord.push_back({a[i], i});
  }

  sort(ord.begin(), ord.end(), greater<pair<ll, int>>());

  ll ans = 0;
  dp[0][0] = 0;

  for(int sum = 0; sum < n; sum++)
  {
    for(int i = 0; i <= sum; i++)
    {
      int j = sum - i;
      dp[i+1][j] = max(dp[i+1][j], dp[i][j] + ord[sum].first * abs(ord[sum].second - i));
      dp[i][j+1] = max(dp[i][j+1], dp[i][j] + ord[sum].first * abs( (n-1-j) - ord[sum].second ));
      // debug(dp[i+1][j]);
      // debug(dp[i][j+1]);
      // cout << "\n\n\n";
    }
  }

  for(int i = 0; i <= n; i++)
  {
    ans = max(ans, dp[i][n-i]);
  }

  

  cout << ans << endl;


  return 0;
} 