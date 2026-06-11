#include <bits/stdc++.h>
using namespace std;
int main() {
  string S; cin >> S;
  cout << (regex_match(S, regex("(hi)+")) ? "Yes" : "No") << endl;
}