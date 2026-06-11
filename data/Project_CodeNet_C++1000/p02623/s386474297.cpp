#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<long long> as, bs; // 累積和
  as.push_back(0);
  bs.push_back(0);
  
  for (int i=0; i<n; i++) {
    int a;
    cin >> a;
    as.push_back(as[i] + a);
  }
  for (int i=0; i<m; i++) {
    int b;
    cin >> b;
    bs.push_back(bs[i] + b);
  }
  
  // aを固定してbを最大化する、を後方から行う
  int ans = 0;
  int j = 0;
  for (int i = n; i >= 0; i--) {
    if (as[i] > k) continue;
    
    for (; j <= m; j++) {
      if (as[i] + bs[j] > k) {
        break;
      }
      ans = max(ans, i + j);
    }
  }
  
  cout << ans;
}