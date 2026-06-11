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
int n, k;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  vector<int> p(n);
  vector<ll> c(n);

  REP(i, n) {
    int t;
    cin >> t;
    t--;
    p[i] = t;
  }

  REP(i, n) cin >> c[i];

  ll ans = -LLINF;
  REP(i, n) {
    int n_p = i;
    ll sum = 0, d = -LLINF;
    vector<ll> dp;
    while(dp.size() <= 0 || n_p != i) {
      n_p = p[n_p];
      sum += c[n_p];
      d = max(d, sum);
      dp.push_back(d);
    }

    ll t = 0;
    if(sum > 0 && k / dp.size()) {
      ll t1 = 0, t2 = 0;
      if(k % dp.size()) t1 += dp[k % dp.size() - 1];
      t1 += sum * (k / dp.size());

      t2 += sum * ((k / dp.size()) - 1);
      t2 += dp[dp.size() - 1];
      t = max(t1, t2);
    } else {
      t = dp[min((int)dp.size() - 1, k - 1)];
    }
    ans = max(ans, t);
  }
  cout << ans << endl;
}
