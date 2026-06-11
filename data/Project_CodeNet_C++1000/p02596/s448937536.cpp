#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int r = 7 % N;
  for (int i = 0; i < N; i++) {
    if (r == 0) {
      cout << i + 1 << endl;
      return 0;
    } else {
      r = (10*r + 7) % N;
    }
  }
  cout << -1 << endl;
}