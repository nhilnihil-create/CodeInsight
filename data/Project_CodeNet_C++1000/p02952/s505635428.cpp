#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 0;

  for (int i = 1; i <= n; i++) {
    int digit  = 0;
    int x = i;
    while(x > 0){
    x  = x / 10;
      digit++;
    }
    if (digit % 2 != 0) ans++;
  }

  cout << ans;

}