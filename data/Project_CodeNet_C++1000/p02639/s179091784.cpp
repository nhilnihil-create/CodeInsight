#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> x(5);
  int num = 0;
  cin >> x[1] >> x[2] >> x[3] >> x[4] >> x[5];
  for (int i = 1; i <= x.size(); i++) {
    if (x[i] == 0) {
      num = i;
    }
  }
  cout << num << endl;
}