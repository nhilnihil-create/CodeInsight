#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  bool flag = true;
  for (int i = 0; i < 3; i++) {
    if (N % 10 == 7) {
      cout << "Yes" << endl;
      flag = false;
      break;
    } else {
      N /= 10;
    }
  }
  if (flag) {
    cout << "No" << endl;
  }
}