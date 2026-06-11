#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, B;
  cin >> A >> B;

  int ans = (B - 1) / (A - 1);
  if ((B - 1) % (A - 1) > 0) {
    ans++;
  }

  cout << ans << endl;

  return 0;
}
