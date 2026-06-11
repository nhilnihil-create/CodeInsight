#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int count = 0;
  if (S.size() % 2 == 0) {
    for (int i = 0; i < S.size()/2; i++) {
      if (S.at(i) != S.at(S.size() - i - 1)) {
        count++;
      }
    }
  } else {
    for (int i = 0; i < (S.size() - 1)/2; i++) {
      if (S.at(i) != S.at(S.size() - i - 1)) {
        count++;
      }
    }
  }
  cout << count << endl;
}