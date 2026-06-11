#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  int a = S.size();
  if(S.at(a-1)=='s'){
    cout << S << "es" << endl;
  }
  else{
    cout << S << "s" << endl;
  }
}