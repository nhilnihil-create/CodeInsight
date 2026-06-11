#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ll A, V, B, W; cin >> A >> V >> B >> W;
  ll T; cin >> T;

  if (V < W) {
    cout << "NO" << endl;
    return 0;
  }

  if ((V - W) * T >= max(A - B, B - A)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
