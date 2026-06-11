#include<bits/stdc++.h>

using namespace std;

int main()
{
  string s,s1;
  cin>>s>>s1;
  int c=0;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]!=s1[i])c++;
  }
  cout<<c<<endl;

}