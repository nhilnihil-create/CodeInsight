#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string S, T;
  cin >> S >> T;
  
  if(T.size() != S.size()+1) cout << "No" << endl;
  
  else {
    
    for(int i = 0; i < S.size(); i++) {
      
      if(S.at(i) != T.at(i)) {
        cout << "No" << endl;
        break;
      }
      
      else {
        if(i == S.size() -1) cout << "Yes" << endl;
        else continue;
      }
      
    }
    
  }
  
}