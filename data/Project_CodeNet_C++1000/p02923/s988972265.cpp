#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int N;
  cin >> N;
  int H[N];
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  int ans = 0;
  int v = 0;
  for (int i = 0; i < N - 1; i++) {
    if (H[i] >= H[i + 1]) v++;
    else v = 0;
    ans = max(ans, v);
  }
  cout << ans << "\n";
  return 0;
}