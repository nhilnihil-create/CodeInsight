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
// << fixed << setprecision
// --------------------------------------
string s;
ll dp[100005][15];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> s;

  dp[0][0] = 1;
  int l = (int)s.size();
  REP(i, l) {
    if(s[i] == '?') {
      REP(j, 13) REP(k, 10) {
        int t = (j * 10 + k) % 13;
        dp[i + 1][t] += dp[i][j];
        dp[i + 1][t] = dp[i + 1][t] % mod;
      }
    } else {
      REP(j, 13) {
        int st = s[i] - '0';
        int t = (j * 10 + st) % 13;
        dp[i + 1][t] += dp[i][j];
        dp[i + 1][t] = dp[i + 1][t] % mod;
      }
    }
  }

  cout << dp[l][5] << endl;
}
