#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, A, B;
  cin >> K >> A >> B;
  bool ans = false;
  for (int i = 1; i <= 1000; i++) {
    if (K * i >= A && K * i <= B)
      ans = true;
    if (ans == 1) {
      cout << "OK" << endl;
      break;
    }
  }
  if (ans == 0)
    cout << "NG" << endl;
}
