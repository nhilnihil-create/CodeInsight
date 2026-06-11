#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <bitset>
#include <set>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};
int dx9[9]={0,1,0,-1,1,-1,1,0,-1};
int dy9[9]={0,1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;
typedef pair<ll, ll> PLL;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;

// --------------------------------------
int n, t;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> t;
  vector<P> ab;

  REP(i, n) {
    int a, b;
    cin >> a >> b;
    ab.push_back(P(a, b));
  }

  sort(ab.begin(), ab.end());

  int dp[n + 1][6001];

  REP(i, n) {
    REP(j, 6001) {
      if(j - ab[i].first >= 0 && j - ab[i].first < t) {
        dp[i + 1][j] = max(dp[i][j - ab[i].first] + ab[i].second, dp[i][j]);
      } else {
        dp[i + 1][j] = dp[i][j];
      }
    }
  }

  int ans = 0;
  REP(i, 6001) ans = max(ans, dp[n][i]);

  cout << ans << endl;
}
