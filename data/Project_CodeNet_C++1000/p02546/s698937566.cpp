#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int l = s.size();
  if(s.at(l-1) == 's') s.push_back('e');
  s.push_back('s');
  
  cout << s << endl;
}