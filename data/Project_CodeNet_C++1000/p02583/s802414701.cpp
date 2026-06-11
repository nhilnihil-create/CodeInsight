#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  for (int i = 0; i < N; i++) cin >> L.at(i);
  
  if (N < 3) cout << "0" << endl;
  
  else {
    int ans = 0;
    for (int i = 0; i < N - 2; i++) {
      for (int j = i + 1; j < N - 1; j++) {
        for (int k = j + 1; k < N; k++) {
          int Li = L.at(i), Lj = L.at(j), Lk = L.at(k);
          if (Li == Lj || Lj == Lk || Lk == Li) continue;
          else if (Li + Lj > Lk && Lj + Lk > Li && Lk + Li > Lj) ans += 1;
        }
      }
    }
  
  cout << ans << endl;
  }
}