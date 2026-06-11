#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  if(S[0] == 'R'){
    if(S[1] == 'R'){
      if(S[2] =='R'){
        cout << 3 << endl;
      } else {
        cout << 2 << endl;
      }
    } else {
      cout << 1 << endl;
    }
  } else {
    if(S[1] =='R'){
      if(S[2] == 'R'){
        cout << 2 << endl;
      } else {
        cout << 1 << endl;
      }
    } else if(S[2] == 'R'){
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
}
