#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int N, K; cin >> N >> K;
  vector<int> p;

  for (int i = 0; i < N; i++) {
    int n; cin >> n;
    p.push_back(n);
  }
  sort(p.begin(), p.end());

  int ans = 0;
  for (int i = 0; i < K; i++) {
    ans += p[i];
  }
  
  cout << ans << endl;

  return 0;
}