#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  vector<char> V(4);
  for (int i = 0; i < 4; i++) {
    V.at(i) = S.at(i);
  }
  sort(V.begin(), V.end());
  if (V.at(0) == V.at(1) && V.at(1) != V.at(2) && V.at(2) == V.at(3)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}