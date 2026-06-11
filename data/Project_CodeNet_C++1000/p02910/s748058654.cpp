#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  bool b = true;
  for(int i = 0; i < s.size(); i++) {
    if(i % 2 == 0 && s.at(i) == 'L')
      b = false;
    if(i % 2 == 1 && s.at(i) == 'R')
      b = false;
  }
  cout << (b? "Yes" : "No") << endl;
  return 0;
}