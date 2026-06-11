#include "bits/stdc++.h"
using namespace std;
string fun(){
  string S,T;
  cin >> S >> T;
  if (S == T.erase(T.size()-1)) return "Yes";
  else return "No";
}

int main(){
  cout << fun() << endl;
  return 0;
}