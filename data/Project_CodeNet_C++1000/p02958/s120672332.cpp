#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, x = 0, a = 0, b = 0, flag = 0;
  string ans = "YES";
  cin >> N;
  
  for (int i = 1; i <= N; i++) {
    cin >> x;
    if (i != x && flag == 2) break;
    if (i != x && flag == 1) {
      if (x == a && i == b) ans = "YES";
      flag = 2;
    }
        if (i != x && flag == 0) {
      a = i;
      b = x;
      flag = 1;
      ans = "NO";
    }
  }
  
  cout << ans << endl;
}
