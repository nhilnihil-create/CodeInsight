#include<bits/stdc++.h>
using namespace std;
int main(){
  string s, S, ES;
  int LONGS;
  
  S = 's';
  ES = "es";
  
  cin >> s;
  
  LONGS = (int) s.size();
  
  if(s[LONGS-1] == 's') s += ES;
  else s += S;
  
  cout << s << endl;
  
  return 0;
}