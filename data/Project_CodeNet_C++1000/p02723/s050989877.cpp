#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  bool sim = false;
  if(s.at(2) == s.at(3)){
    if(s.at(4) == s.at(5)){
      cout << "Yes" << endl;
      sim = true;
    }
  }
  
  if(!sim) cout << "No" << endl;
  
    
}