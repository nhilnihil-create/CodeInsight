#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int T = 0, U = S.size();
  for (int i = 0; i < U / 2; i++) {
    if (S.at(i) != S.at(U - 1 - i)) {T++;}
  }
  cout << T << endl;
}