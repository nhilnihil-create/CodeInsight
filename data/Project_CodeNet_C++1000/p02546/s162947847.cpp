#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int l=s.length();
  if(s[l-1]=='s')
    cout<<s<<"es";
  else
    cout<<s<<"s";
  return 0;
}