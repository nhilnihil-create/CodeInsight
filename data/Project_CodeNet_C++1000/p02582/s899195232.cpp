#include <bits/stdc++.h>
using namespace std;

int FindRainyDays(string& S) {
  int max_length = 0;
  int count = 0;
  for (int i = 0; i < S.length(); ++i) {
    if (S[i] == 'R') {
      count++;
    }
    else {
      max_length = max(max_length, count);
      count = 0;
    }
  }
  max_length = max(max_length, count);
  return max_length;
}

int main() {
  string S;
  cin >> S;
  cout << FindRainyDays(S) << endl;
}
