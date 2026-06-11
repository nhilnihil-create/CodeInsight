#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  cout << ((S.at(2) == S.at(3) && S.at(4) == S.at(5)) ? "Yes" : "No") << "\n";
}