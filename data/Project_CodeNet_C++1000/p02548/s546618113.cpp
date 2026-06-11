#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  long long ans = 0;
  for(long long a = 1; a < n; a++) {
    for(long long b = a; a * b < n; b++) {
      if (a == b) ans++;
      else ans += 2;
    }
  }
  cout << ans;
}