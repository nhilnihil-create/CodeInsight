#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
  
  string S; cin >> S;
  
  if (C < D) {
    
    for (int i = A; i < D - 1; i++) {
      if (S.at(i) == '#' && S.at(i + 1) == '#') {
        cout << "No" << endl; return 0;
      }
    }
    
    cout << "Yes" << endl;
    
  }
  else {
    
    bool flagOfSpace = false, flagOfRock = true;
    
    for (int i = B - 2; i < D - 1; i++) {
      if (S.at(i) == '.' && S.at(i + 1) == '.' && S.at(i + 2) == '.') {
        flagOfSpace = true;
      }
    }
    
    for (int i = A; i < C - 1; i++) {
      if (S.at(i) == '#' && S.at(i + 1) == '#') {
        flagOfRock = false;
      }
    }
    
    if (flagOfSpace && flagOfRock) cout << "Yes" << endl;
    
    else cout << "No" << endl;
    
  }
  
}