#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N, K;
  cin >> N >> K;
  vector<int> H(N);
  int64_t sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
    sum += H.at(i);
  }
  sort(H.begin(), H.end());
  reverse(H.begin(), H.end());
  int64_t sum2 = 0;
  if (K < N) {
    for (int i = 0; i < K; i++) {
      sum2 += H.at(i);
    } 
  }
  else {
    for (int i = 0; i < N; i++) {
      sum2 += H.at(i);
    } 
  }
  int64_t ans = sum - sum2; 
  cout << ans << endl;
}
