#include <bits/stdc++.h>
using namespace std;
int pow(int x) {
  return x * x;
}
int main() {
  int N, D;
  cin >> N >> D;
  vector<vector<int>> vec(N, vector<int>(D));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < D; j++) {
      cin >> vec[i][j];
    }
  }
  int ans = 0;
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      int d_pow = 0;
      for(int k = 0; k < D; k++) {
        d_pow += pow(vec[i][k] - vec[j][k]);
      }
      for(int i = 0; i < 130; i++) {
        if(pow(i) == d_pow) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}