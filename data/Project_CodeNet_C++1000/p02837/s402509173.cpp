#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<vector<int>> testimony(N, vector<int>(N, -1));
  int to_x, to_y;
  for(int i = 0; i < N; ++i) {
    int A;
    cin >> A;
    for(int j = 0; j < A; ++j) {
      int x, x_is;
      cin >> x >> x_is;
      testimony[i][x - 1] = x_is;
    }
  }

  int ans = 0;
  for(int i = 0; i < (1 << N); ++i) {
    vector<int> pattern(N);
    for(int j = 0; j < N; ++j) {
      if(i >> j & 1) {
        pattern[j] = 1;
      }
    }

    bool testimony_of_all = true;
    for(int j = 0; j < N; ++j) {
      if(pattern[j]) {
        for(int k = 0; k < N; ++k) {
          if(testimony[j][k] == -1) continue;
          if(testimony[j][k] != pattern[k]) testimony_of_all = false;
        }
      }
    }
    if(testimony_of_all) ans = max(ans, __builtin_popcount(i));
  }

  cout << ans << endl;

  return 0;
}
