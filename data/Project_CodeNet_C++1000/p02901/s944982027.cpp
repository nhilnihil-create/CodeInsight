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
int n, m;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  vector<int> a(m);
  vector<int> t[m];

  REP(i, m) {
    int b;
    cin >> a[i] >> b;
    REP(j, b) {
      int c;
      cin >> c;
      c--;
      t[i].push_back(c);
    }
  }

  int dp[10000];
  REP(i, 10000) dp[i] = INF;
  dp[0] = 0;

  REP(i, m) {
    int h = 0;
    for(int u : t[i]) h |= (1 << u);
    REP(j, 1 << n) {
      int now = j | h;
      dp[now] = min(dp[now], dp[j] + a[i]);
    }
  }

  cout << (dp[(1 << n) - 1] == INF ? -1 : dp[(1 << n) - 1]) << endl;
}
