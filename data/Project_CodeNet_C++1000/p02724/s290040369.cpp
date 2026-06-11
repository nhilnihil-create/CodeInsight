#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;
  vector<int> count = {0, 0};
  while (X >= 500) {
    count.at(0) += 1;
    X -= 500;
  }
  while (X >= 5) {
    count.at(1) += 1;
    X -= 5;
  }
  cout << 1000 * count.at(0) + 5 * count.at(1) << endl;
}