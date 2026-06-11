#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, N;
  cin >> H >> W >> N;

  int ans = 0;
  while (N > 0) {
    N -= max(H, W);
    ans++;
  }

  cout << ans << endl;
}