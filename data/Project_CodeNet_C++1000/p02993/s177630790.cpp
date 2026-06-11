#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  bool ans=false;
  if(s[0]==s[1]) ans=true;
  if(s[1]==s[2]) ans=true;
  if(s[2]==s[3]) ans=true;
  puts(ans?"Bad":"Good");
  return 0;
}
  
     