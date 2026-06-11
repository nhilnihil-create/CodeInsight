#include<bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin>>s;
 int l=s.length();
  if(s[l-1]=='s')
    cout<<s<<"es"<<"\n";
  else
    cout<<s<<"s"<<"\n";
}