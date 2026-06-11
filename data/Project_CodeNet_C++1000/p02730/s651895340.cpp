#include <bits/stdc++.h>
using namespace std;

bool f(string x){
  int n = x.size();
  for(int i = 0; i < n/2 ; i++){
    if(x.at(i) != x.at(n - 1 - i)){
      return false;
      break;
    }
  }
  return true;
}
    
int main(){
  string S;
  cin >> S;
  
  bool m = false;
  int n = S.size();
    
  
  string s1;
  string s2;
  
  if(f(S)){
    s1 = S.substr(0,(n - 1)/2);
    s2 = S.substr((n + 1)/2);
    
    if(f(s1)){
      if(f(s2)){
        m = true;
      }
    }
  }
  
  if(m) cout << "Yes" << endl;
  if(!m) cout << "No" << endl;
  return 0;
}