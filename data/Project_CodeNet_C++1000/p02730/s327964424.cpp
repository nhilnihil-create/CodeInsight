#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  for (int i = 0; i < (S.size() - 1)/2; i++) {
    if (S.at(i) != S.at(S.size() - i - 1)) {
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i = 0; i < (S.size() - 1)/2; i++) {
    if (S.at(i) != S.at((S.size()-1)/2 - i - 1)) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}