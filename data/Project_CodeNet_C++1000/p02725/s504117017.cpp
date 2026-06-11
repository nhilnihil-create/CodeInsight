#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, n, a1, b, m = 0;
  cin >> k >> n;
  for(int i = 0;i < n;i++) {
    if(i == 0) {
      cin >> a1;
      b = a1;
    } else {
      int a;
      cin >> a;
      if(a - b > m) m = a - b;
      b = a;
      if(i == n - 1 && a1 + k - a > m) m = a1 + k - a;
    }
  }
  cout << k - m << endl;
}