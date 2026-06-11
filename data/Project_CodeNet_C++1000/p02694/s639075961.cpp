#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t X;
  cin >> X;
  int64_t memo = 100;
  for (int i = 0; i < 3760; i++) {
    if (memo + memo / 100 >= X) {
      cout << i + 1 << endl;
      break;
    }
    else {
       memo = memo + memo / 100;
    }
  }
}