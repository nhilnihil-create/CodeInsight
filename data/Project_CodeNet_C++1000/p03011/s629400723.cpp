#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int P, Q, R;
  cin >> P >> Q >> R;

  int tot = P + Q + R;
  int del = max({P, Q, R});
  cout << tot - del << endl;
}