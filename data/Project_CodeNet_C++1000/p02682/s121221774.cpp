#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int A, B, C, K, ans;
  cin >> A >> B >> C >> K;
  if (A >= K) ans = K;
  else if (A + B >= K) ans = A;
  else ans = 2 * A + B - K;
  cout << ans << endl;
}