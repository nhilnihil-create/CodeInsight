#include <bits/stdc++.h>
using namespace std;


int main() {
  string s;
  
  cin >> s;
  
  int flag = 0;
  
  for(int i=1; i<s.size(); i++){
    if(s.at(0) == s.at(i))
      flag++;
  }
  
  for(int i=2; i<s.size(); i++){
    if(s.at(1) == s.at(i))
      flag++;
  }
  
  for(int i=3; i<s.size(); i++){
    if(s.at(2) == s.at(i))
      flag++;
  }
  
  if(flag == 2)
    cout << "Yes";
  
  else
    cout << "No";
  
}