#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  
  vector<int> m(N);
  for (int i = 0; i < N; i++) {
    cin >> m.at(i);
  }
  
  sort(m.begin(), m.end());
  
  int ans = 0;
  for (int i = 0; i < K; i++) {
    ans = ans + m.at(i);
  }
  
  cout << ans << endl;
}
