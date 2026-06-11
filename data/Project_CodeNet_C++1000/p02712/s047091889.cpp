#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, ans = 0;
  cin >> N;
  
  for (int i = 0; i <= N; i++) {
    if (i%3 != 0 && i%5 != 0) ans += i;
  }

  cout << ans << endl;
}