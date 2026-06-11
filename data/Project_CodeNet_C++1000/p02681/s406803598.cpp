#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s,t;
  cin>>s;
    cin>>t;
  int l=s.size(),c=0;
  int p=t.size();
  for(int i=0;i<l;i++)
  {
    if(s[i]!=t[i])
      c++;
      
  }
  if(c==0)
    cout<<"Yes";
  else
    cout<<"No";
  
}