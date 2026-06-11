#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int A, B, C;
  cin >> A >> B >> C;
  bool ok = false;
  if (A == B && B == C) {
  }
  else if (A == B | B == C | A == C) {
    ok = true;
  }
  if (ok) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
    
}