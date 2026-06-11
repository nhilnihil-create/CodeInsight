#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int tm[3];
  for (int i = 0; i < 3; i++) {
    cin >> tm[i];
  }
  sort(tm, tm + 3);

  cout << tm[0] + tm[1] << endl;
  return 0;
}
