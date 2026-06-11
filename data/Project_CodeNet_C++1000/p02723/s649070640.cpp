#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  
  if(S.at(2) == S.at(3) && S.at(4) == S.at(5)){
    cout << "Yes" << endl;
    return 0;
  }
  else{
    cout << "No" << endl;
    return 0;
  }
}