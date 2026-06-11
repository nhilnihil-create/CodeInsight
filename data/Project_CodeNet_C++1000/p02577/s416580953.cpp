#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int byk=0;
  for(int i=0;i<s.length();i++){
 	byk+=(s[i]-'0');
  }
  if(byk%9==0)puts("Yes");
  else puts("No");
  return 0;
}