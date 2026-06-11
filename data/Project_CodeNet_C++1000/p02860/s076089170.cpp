#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  if(n&1)puts("No");
  else {
    string t = s.substr(0,n/2);
    string g = s.substr(n/2,n/2);
    if(g==t)puts("Yes");
    else puts("No");
  
  }
  return 0;
}