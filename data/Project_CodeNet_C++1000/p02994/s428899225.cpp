#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, L, a = 0, ajimin = 100, tmp = 0, ans = 0;
  cin >> N >> L;
  
  for (int i = 1; i <= N; i++) {
    a += L + i - 1;
    tmp = L + i - 1;
    if (abs(ajimin) > abs(tmp)) ajimin = tmp;
  }
  ans = a - ajimin;
  
  cout << ans << endl;
}