#include <iostream>
#include <vector>
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
using namespace std;
int N, K;
vector<long long> P(5000), C(5000);

int main() {

  cin >> N >> K;
  
  rep(i,N) {
    cin >> P[i];
    --P[i];
  }
  rep(i,N) cin >> C[i];
  
  long long ans =  -1e18;
  // 始点を全て試す
  rep(i, N) {
    //　一周期試す
    vector<int> list; // 周期のコストリスト
    int now = i;
    ll cycle_sum = 0; // 一周期の合計
    for (;;) {
      cycle_sum += C[now];
      list.push_back(C[now]);
      now = P[now];
      if (now == i) break;
    }
    
    // 周期を回して答えを更新する
    ll cycle = 0;
    for (int j = 0; j < list.size(); j++) {
      if (j >= K) break;
      cycle += list[j];
      ll cycle_ans = cycle;
      
      if (cycle_sum > 0) {
        ll e = (K - j - 1) / list.size();
        cycle_ans += e * cycle_sum;
      }
      ans = max(cycle_ans, ans);
    }
  }
  
  cout << ans;
}