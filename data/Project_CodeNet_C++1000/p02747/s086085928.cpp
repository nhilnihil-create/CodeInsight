#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string S;
  string hi = "hi";
  cin >> S;
  bool ans = S.length() % 2 == 0;
  for (int i = 0; i < S.length(); i++) {
    ans &= S[i] == hi[i % 2];
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}