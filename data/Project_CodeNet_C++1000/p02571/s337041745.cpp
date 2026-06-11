#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s,t;cin>>s>>t;int k=INT_MIN;
  for(int i=0;i<=s.length()-t.length();i++)
  {
    int p=0;
    for(int j=0;j<t.length();j++)
    {
      if(s[j+i]==t[j])
         {p++;}
         }
         k=max(p,k);
         }
         cout<<t.length()-k;
         }

