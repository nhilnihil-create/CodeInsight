#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int X; cin >> X;
  
  int shimoni = X % 100;
  int cnt = 0;
  while (shimoni > 0) {
    if (shimoni >= 5) {
      shimoni -= 5;
      cnt++;
    } else if (shimoni >= 4) {
      shimoni -= 3;
      cnt++;
    } else if (shimoni >= 3) {
      shimoni -= 3;
      cnt++;
    } else if (shimoni >= 2) {
      shimoni -= 2;
      cnt++;
    } else if (shimoni >= 1) {
      shimoni -= 1;
      cnt++;
    }
  }
  cout << (X/100 >= cnt ? "1" : "0") << endl;
  return 0;
}