#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, h, ans = 0;
  cin >> N >> K;
  
  for (int i = 0; i < N; i++) {
    cin >> h;
    if (h >= K) ans += 1;
  }
  
  cout << ans << endl;;
}