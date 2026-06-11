#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, A, B;
  cin >> K >> A >> B;
  bool flag = true;
  for (int i = 1; i * K <= 1000; i++) {
    if (A <= i * K && i * K <= B) {
      cout << "OK" << endl;
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << "NG" << endl;
  }
}