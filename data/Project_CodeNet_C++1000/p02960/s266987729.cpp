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

ll dp[maxn][13];


int main()
{
  ios::sync_with_stdio(0);
  string s;
  cin >> s;
  
  dp[0][0] = 1;
  for(int i = 0 ; i < s.size(); i++)
  {
    for(int j = 0 ; j < 13; j++)
    {
      if(s[i] == '?')
      {
        for(int k = 0 ; k < 10; k++)
        {
          dp[i+1][(k + j * 10) % 13] += dp[i][j];
          dp[i+1][(k + j * 10) % 13] %= mod;
        }
      }
      else
      {
        dp[i+1][(s[i] - '0' + j * 10) % 13] += dp[i][j];
        dp[i+1][(s[i] - '0' + j * 10) % 13] %= mod;
      }
    }
  }

  cout << dp[s.size()][5] << endl;
  
  return 0;
}