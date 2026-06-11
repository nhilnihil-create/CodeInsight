#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

typedef long long ll;
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i = 1; i < n; i++) {
    for(int j = i + 1; j <= n; j++) {
      int ijxor = (i ^ j);
      int ans = 1;
      while((ijxor & 1) == 0) {
        ans++;
        ijxor = ijxor >> 1;
      }
      cout << ans << " ";
    }
    cout << "\n";
  }
  return 0;
}

