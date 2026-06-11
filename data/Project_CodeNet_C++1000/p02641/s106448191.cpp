#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int X, N;
  cin >> X >> N;
  vector<int> p(N);
  for (int i = 0; i < N; i++) cin >> p.at(i);
  for (int i = 0; i <= 50; i++) {
    bool flag1 = true;
    bool flag2 = true;
    for (int j = 0; j < N; j++) {
      if (X - i == p.at(j)) {
        flag1 = false;
      }
      if (X + i == p.at(j)) {
        flag2 = false;
      }
    }
    if (flag1) {
      cout << X - i << endl;
      break;
    } else if (flag2) {
      cout << X + i << endl;
      break;
    }
  }
}