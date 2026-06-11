#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  int ans = 0;
  int memo = 0;
  for (int i = 0; i < N - 1; i++) {
    if (H.at(i) >= H.at(i + 1)) {
      memo++;
    }
    else {
      ans = max(ans, memo);
      memo = 0;
    }
    if (i == N - 2) {
      ans = max(ans, memo);
    }
  }
  cout << ans << endl;   
}