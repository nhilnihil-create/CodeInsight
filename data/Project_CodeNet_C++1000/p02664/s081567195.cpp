#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  for (char c : S) cout << ((c == '?') ? 'D' : c);
  cout << "\n";
}