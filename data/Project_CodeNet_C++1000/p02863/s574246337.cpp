#include<bits/stdc++.h>
using namespace std;

int main() {
  int N, T;
  cin >> N >> T;
  struct Data {int A, B;};
  vector<Data> food(N);
  for(auto& f: food) cin >> f.A >> f.B;
  sort(begin(food), end(food), [](auto l, auto r) {return (l.A!=r.A) ? (l.A<r.A) : (l.B>r.B);});
  int ans = 0;
  vector<int> dp(6000+1);
  for(auto f: food) {
    auto a = f.A, b = f.B;
    for(int i=T-1; 0<=i; --i) {
      dp[i+a] = max(dp[i+a], dp[i]+b);
      ans = max(ans, dp[i+a]);
    }
  }
  cout << ans << endl;
}
