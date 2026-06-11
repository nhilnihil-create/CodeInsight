#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> vec(N);
  rep(i, N) vec.at(i) = i + 1;
  for (int i = 0; i < K; i++) {
    int d;
    cin >> d;
    for (int j = 0; j < d; j++) {
      int x;
      cin >> x;
      rep(i, N) {
        if (x == vec.at(i)) {
          vec.at(i) = 0;
        }
      }
    }
  }
  int ans = 0;
  rep(i, N) {
    if (vec.at(i) != 0) ans++;
  }
  cout << ans << endl;
}