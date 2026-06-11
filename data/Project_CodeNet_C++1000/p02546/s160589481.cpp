#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int n = s.size();
  if(s[n-1]!='s') s+="s";
  else s+= "es";
  cout<<s;
}