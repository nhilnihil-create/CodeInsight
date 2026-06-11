#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;
const int INF = 1001001001;
const int dx[] = {0, 1};
const int dy[] = {1, 0};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  vector<vector<int>> dp(h, vector<int>(w, INF));
  if(s[0][0] == '#') dp[0][0] = 1;
  else dp[0][0] = 0;
  rep(i, h)rep(j, w) {
    rep(k, 2) {
      int nx = dx[k] + i;
      int ny = dy[k] + j;
      if (nx < h && ny < w) {
        int nextv = dp[i][j];
        if (s[i][j] == '.' && s[nx][ny] =='#') nextv++;
        chmin(dp[nx][ny], nextv);
      }
    }
  }

  int ans = dp[h - 1][w - 1];
  cout << ans << endl;
}