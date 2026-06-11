#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;
  vector<bool> flag(N);
  for (int i = 0; i < K; i++) {
    int d;
    cin >> d;
    for (int j = 0; j < d; j++) {
      int A;
      cin >> A;
      flag[A - 1] = true;
    }
  }

  int ans = 0;
  rep(i, N) ans += !flag[i];
  cout << ans << endl;
}