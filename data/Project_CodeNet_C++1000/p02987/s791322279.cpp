#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  if (S[0] == S[1]) {
    if (S[2] == S[3] && S[0] != S[2]) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  else if (S[0] == S[2]) {
    if (S[1] == S[3] && S[0] != S[1]) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  else if (S[0] == S[3]) {
    if (S[1] == S[2] && S[0] != S[1]) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  else cout << "No" << endl;
}
