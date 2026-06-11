#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dp[2];

int main() {
  // dp、金額ちょうどと金額+1の支払う最小の枚数を保持
  string S;
  cin >> S;
  dp[1] = 1;
  for (char s : S) {
    int cur = s - '0';
    int prev[] = {0, 0};
    swap(dp, prev);
    dp[0] = min(prev[0] + cur, prev[1] + (10-cur));
    if (cur <= 8) {
      dp[1] = min(prev[0] + cur + 1, prev[1] + (10-cur-1));
    } else {
      dp[1] = prev[1];
    }
  }
  cout << dp[0] << '\n';
  return 0;
}