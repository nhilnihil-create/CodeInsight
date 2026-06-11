#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, D, look = 0, ans = 0;
  
  cin >> N >> D;
  
  while (look < N) {
    look += 2 * D + 1;
    ans++;
  }
  
  cout << ans << endl;
  
  return 0;
}