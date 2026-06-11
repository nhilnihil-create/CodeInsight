#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <deque>
#include <numeric>
#include <map>
#define rep(i,n) for (int i = 0; i < (n); ++i)
 
using namespace std;
 
typedef pair<int,int> P;
typedef long long ll;

const int  SIZE = 200005;
const ll INF = 1e18 + 10;

struct Key {
  int cost;
  int m = 0;
  Key(int cost) : cost(cost) {}
};

int N, M;
int a, b, c;
ll dp[5005][5005];

int main() {
    cin >> N >> M;
    vector<Key> keys;
    rep(i,M) {
      cin >> a >> b;
      keys.emplace_back(a);
      rep(i,b) {
        cin >> c;
        c--;
        keys.back().m |= (1 << c);
      }
    }
    rep(i,5005) rep(j,5005) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i,M+1) rep(j,1<<N) {
      if (dp[i][j] == INF) continue;
      dp[i + 1][j] = min(dp[i+1][j], dp[i][j]);
      dp[i+1][j | keys[i].m] = min(dp[i+1][j | keys[i].m], dp[i][j] + keys[i].cost);
    }
    if (dp[M][(1<<N)-1] == INF) {
      cout << -1 << endl;
      return 0;
    }
    cout << dp[M][(1<<N)-1] << endl;
}