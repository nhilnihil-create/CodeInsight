#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, K, ans = 0;
  cin >> N >> K;
  vector<int> item(N);
  for (int i = 0; i < N; i++) cin >> item.at(i);
  sort(item.begin(), item.end());
  
  for (int j = 0; j < K; j++) {
    ans = ans + item.at(j);
  }
  
  cout << ans << endl;
}