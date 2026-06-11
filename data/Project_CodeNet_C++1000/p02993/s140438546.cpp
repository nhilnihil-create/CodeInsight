#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int n = 1;
  for (int i=0 ; i<3 ; i++){
    if (s.at(i) == s.at(i+1)){
      n = 0;
      break;
    }
  }
  
  if (n == 1)
    cout << "Good" << endl;
  else
    cout << "Bad" << endl;
}