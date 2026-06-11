#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  
  if(S.at(0) == S.at(1)){
    cout << "Bad" << endl;
    return 0;
  }
  if(S.at(1) == S.at(2)){
    cout << "Bad" << endl;
    return 0;
  }
  if(S.at(2) == S.at(3)){
    cout << "Bad" << endl;
    return 0;
  }
  
  cout << "Good" << endl;
}
  