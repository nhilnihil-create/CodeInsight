#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int A, B;
  cin >> A >> B;
  for (int i = 13; i < 1300; i++) {
    if (i * 8/100 == A && i * 1/10 == B) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}