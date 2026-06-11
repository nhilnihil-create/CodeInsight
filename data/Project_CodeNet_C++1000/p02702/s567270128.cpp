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
const double EPS = 1e-10;

inline int cmp(double x, double y = 0) 
{  
  if(fabs(x - y) < EPS)
    return 0;
  return x > y ? 1 : -1;
}


int main()
{
  string s;
  ios::sync_with_stdio(0);
  cin >> s;
  int n = s.size();
  vector<ll>dp(2020, 0);
  ll ans = 0;
  for(const auto &c : s)
  {
    vector<ll>newDp(2020, 0);
    newDp[c - '0']++;
    for(int i = 0 ; i < 2019; i++)
    {
      newDp[(i * 10 + c - '0') % 2019] += dp[i];
    }
    dp = newDp;
    ans += dp[0];
  }
  cout << ans << endl;
  return 0;
}