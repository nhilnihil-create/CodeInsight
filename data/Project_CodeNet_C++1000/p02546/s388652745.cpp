#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s; cin>>s;
  int n=s.size()-1;
  if(s[n]=='s') {cout<<s+"es"<<endl; }
  else { cout<<s+'s'<<endl;}
  return 0;
}