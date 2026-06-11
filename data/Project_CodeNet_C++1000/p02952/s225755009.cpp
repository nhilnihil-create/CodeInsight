#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (i / 10 == 0) {
      ans++;
    }
    else if (i / 100 != 0 && i / 1000 == 0) {
      ans++;
    }
    else if (i / 100 != 0 && i / 10000 != 0 && i / 100000 == 0) {
      ans++;
    }
  }
  cout << ans << endl;
}