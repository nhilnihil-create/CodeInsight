#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int n;
  n = S.size();
  for (int i = 1; i < n; i++) {
    if (S[i] == S[i-1]) {
      cout << "Bad" << endl;
      return 0;
    }
  }
  cout << "Good" << endl;
}