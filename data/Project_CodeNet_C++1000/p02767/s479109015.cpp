#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, O = 0, P = 0, Q = 0;
  cin >> N;
  vector<int> X(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i);
    O += X.at(i);
  }
  O /= N;
  for (int i = 0; i < N; i++) {
    if (O > X.at(i)) {P += (O - X.at(i)) * (O - X.at(i));}
    else {P += (X.at(i) - O) * (X.at(i) - O);}
  }
  for (int i = 0; i < N; i++) {
    if (O + 1 > X.at(i)) {Q += (O + 1 - X.at(i)) * (O + 1 - X.at(i));}
    else {Q += (X.at(i) - O - 1) * (X.at(i) - O - 1);}
  }
  cout << min(P, Q) << endl;
}