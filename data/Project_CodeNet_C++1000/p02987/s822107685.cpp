#include <bits/stdc++.h>
using namespace std;

int main(){
  
  string S;
  cin >> S;
  
  char a1, a2, a3, a4;
  a1 = S.at(0);
  a2 = S.at(1);
  a3 = S.at(2);
  a4 = S.at(3);
  
  if(a1 == a2 && a3 == a4 && a2 != a3) cout << "Yes" << endl;
  else if(a1 == a3 && a2 == a4 && a2 != a3) cout << "Yes" << endl;
  else if(a1 == a4 && a2 == a3 && a2 != a4) cout << "Yes" << endl;
  else cout << "No" << endl;

}