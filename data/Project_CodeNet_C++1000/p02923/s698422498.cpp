#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<long long int> H(N);
  for(int i = 0; i < N; i++) {
    cin >> H[i];
  }
  int ans = 0;
  if(N > 1) {
    for(int i = 0; i < N - 1; i++) {
      int count = 0;
      for(int j = 0; j < N - i - 1; j++) {
        if(H[i + j] >= H[i + j + 1]) {
          count++;
        }
        else {
          break;
        }
      }
      if(count > ans) {
        ans = count;
      }
    }
  }
  cout << ans << endl;
}