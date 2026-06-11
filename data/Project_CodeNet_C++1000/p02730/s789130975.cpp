#include <bits/stdc++.h>
using namespace std;

bool isok(string s){
  string t(s);
  reverse(t.begin(), t.end());
  return s == t;
}

int main(){
  string s; cin >> s;
  int n = (int)s.size();
  
  bool ans = true;
  
  if(!isok(s)) ans = false;
  if(!isok(s.substr(0,n/2))) ans = false;
  if(!isok(s.substr(n/2+1))) ans = false;
  
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}