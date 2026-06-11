#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  char c1, c2, c3, c4;
  c1 = S[0];
  c2 = S[1];
  c3 = S[2];
  c4 = S[3];
  
  if (c1 == c2 && c3 == c4 && c1 != c3) cout << "Yes" << endl;
  else if (c1 == c3 && c2 == c4 && c1 != c4) cout << "Yes" << endl;
  else if (c1 == c4 && c3 == c2 && c1 != c3) cout << "Yes" << endl;
  else cout << "No" << endl;
}