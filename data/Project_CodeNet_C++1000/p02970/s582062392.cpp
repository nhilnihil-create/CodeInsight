#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int D;
  cin >> N >> D;
  int ans = 0;
  if (N % (2 * D + 1) == 0) {
    ans = N / (2 * D + 1);
  }
  else {
    ans = N / (2 * D + 1) + 1;
  }
  cout << ans << endl;
}
     