#include <bits/stdc++.h>
using namespace std;

int main() {
  string S,T;
  cin >> S >> T;
  int sizeS = S.size();
  bool ans = true;
  for ( int i = 0; i < sizeS; i++){
    if (S.at(i) != T.at(i)){
      ans = false;
    }
  }
  if (ans){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }    
}
