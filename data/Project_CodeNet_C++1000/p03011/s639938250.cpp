#include <bits/stdc++.h>
using namespace std;

int main() {
  int P, Q, R;
  cin >> P >> Q >> R;
  vector<int> V = {P, Q, R};
  sort(V.begin(), V.end());
  cout << V.at(0) + V.at(1) << endl;
}