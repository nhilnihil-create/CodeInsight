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

int N;
string S;
int dp[5005][5005];

int main() {
    cin >> N >> S;
    for (int i = N-1; i >= 0; --i) {
      for (int j = N-1; j>=0; --j) {
        if (S[i]!=S[j]) dp[i][j] = 0;
        else dp[i][j] = dp[i+1][j+1] + 1;
      }
    }
    int ans = 0;
    rep(i,N) rep(j,N) {
      if (i>=j) continue;
      int now = min(dp[i][j], j -i );
      ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}