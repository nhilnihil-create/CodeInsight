#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 1; i < 46300; i++) {
    int a = i * 1.08;
    if (a == n) {
      cout << i << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
}