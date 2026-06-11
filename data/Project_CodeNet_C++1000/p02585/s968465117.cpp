#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> P(N), C(N);
  for (int i = 0; i < N; i++) {
    cin >> P.at(i);
    P.at(i)--;
  }
  for (int i = 0; i < N; i++) cin >> C.at(i);
  long long int ans = -1000000000000000000;
  
  for (int i = 0; i < N; i++) {
    int v = i;
    long long int cycle_sum = 0;
    int cycle_cnt = 0;
    while (true) {
      cycle_cnt++;
      cycle_sum += C.at(v);
      v = P.at(v);
      if (v == i) break;
    }
    long long int path = 0;
    int cnt = 0;
    while (true) {
      cnt++;
      path += C.at(v);
      if (cnt > K) break;
      int num = (K - cnt) / cycle_cnt;
      long long int score = path;
      if (cycle_sum > 0) score += cycle_sum * num;
      ans = max(ans, score);
      v = P.at(v);
      if (v == i) break;
    }
  }
  
  cout << ans << endl;
}