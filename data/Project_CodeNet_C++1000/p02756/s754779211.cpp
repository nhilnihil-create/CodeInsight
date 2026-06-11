#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int Q;
  cin >> S >> Q;
  
  string Sf = "";
  string Sb = "";
  int c = 0;
  for (int i = 0; i < Q; i++) {
    int T;
    cin >> T;
    if (T == 1) {
      c += 1;
    }
    else {
      int F;
      char C;
      cin >> F >> C;
      if ((F + c) % 2 == 1) {
        Sf += C;
      }
      else {
        Sb += C;
      }
    }
  }
  
  reverse(Sf.begin(), Sf.end());
  S = Sf + S + Sb;
  
  if (c % 2 == 1) {
    reverse(S.begin(), S.end());
  }
    
  cout << S << endl;
}