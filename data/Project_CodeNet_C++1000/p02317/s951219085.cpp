#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

const int INF = 2000000000;

int main(){
  int n;
  cin >> n;
  vector<int> seq(n);
  rep(i, n) cin >> seq[i];
  vector<int> dp(n);
  rep(i, n) dp[i] = INF;
  rep(i, n){
    int index = lower_bound(dp.begin(), dp.end(), seq[i]) - dp.begin();
    dp[index] = seq[i];
  }
  int ans = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
  cout << ans << endl;
  
  return 0;
}
