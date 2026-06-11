#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) int(x.size())

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const double PI=3.14159265358979323846;

int mod = 1e9+7;
int INF = 1e9+7;
// const long long INF = 1LL<<60;

int dp[3001][3001];

int main(){
  int N, T;
  cin >> N >> T;
  vector<P> item(N); 
  rep(i, N){
    cin >> item[i].first >> item[i].second;
  }

  sort(item.begin(), item.end());

  int ans = 0;
  rep(i, N){
    rep(j, T+1){
      // 使わない
      chmax(dp[i+1][j], dp[i][j]);
      // 使う
      int nj = j + item[i].first;
      if(nj > T) continue;
      dp[i+1][nj] = max(dp[i+1][nj], dp[i][j] + item[i].second);
    }
    int tmp_ans = dp[i][T-1] + item[i].second;
    chmax(ans, tmp_ans);
  }
  cout << ans << endl;

  return 0;
}
