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
#define rep(i,N) for(int (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;
const int INF = 1001001001;
const int MAXL = 5010;
int dp[MAXL][MAXL];

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  rep(i, n) rep(j, n) {
    int ni = i + 1;
    int nj = j + 1;
    chmax(dp[ni][nj], dp[i][j]);
    if(s[i] == s[j]) chmax(dp[ni][nj], dp[i][j] + 1);
    else dp[ni][nj] = 0;
    
  }

  int ans = 0;
  rep(i, n)rep(j, n) {
    // cout <<dp[n][i + 1] << endl;
    if (i >= j) continue;
    int now = min(dp[i + 1][j + 1], j - i);
    ans = max(ans, now);
  }
  cout << ans << endl;
  
}
