#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class in{
public:
  long long s, n;
  bool operator<(const in& another) const{
    return s > another.s;
  }
};

void solve(){
  int n; cin >> n;
  vector<in> a(n + 1);
  for(int i = 0; i < n; i++){
    cin >> a[i + 1].s;
    a[i + 1].n = i + 1;
  }
  sort(a.begin() + 1, a.end());
  //for(int i = 1; i <= n; i++) cout << a[i].s << " " << a[i].n << endl;
  vector<vector<long long> > dp(n + 1, vector<long long>(n + 1));
  dp[0][0] = 0;
  for(int i = 1; i <= n; i++){
    dp[i][0] = dp[i - 1][0] + a[i].s * abs(n - i + 1 - a[i].n);
    for(int l = 1; l < i; l++){
      long long right = dp[i - 1][l] + a[i].s * abs(n - (i - l) + 1 - a[i].n);
      long long left = dp[i - 1][l - 1] + a[i].s * abs(a[i].n - l);
      dp[i][l] = max(right, left);
    }
    dp[i][i] = dp[i - 1][i - 1] + a[i].s * abs(a[i].n - i);
    /*for(int l = 0; l <= i; l++){
      cout << "dp[" << i << "][" << l << "] = " << dp[i][l] << endl;
    }*/
  }
  long long ans = 0;
  for(int i = 1; i <= n; i++){
    for(int l = 0; l <= i; l++){
      ans = max(dp[i][l], ans);
    }
  }
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
