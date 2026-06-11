#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  int N = S.size();
  int M = T.size();
  int ans = INT_MAX;
  for (int i = 0; i < N; i++) {
    int tmp = 0;
    for (int j = 0; j < M; j++) {
      if (i + j >= N) goto NG; 
      if (S.at(i + j) != T.at(j)) tmp++; 
    }
    ans = min(ans, tmp);
    NG:;
  }
  cout << ans << "\n";
}