#include<bits/stdc++.h>
using namespace std;


void solve()
{
  string s,t;
  cin>>s>>t;
  int l1=s.length();
  int l2=t.length();
  int count=0;
  for(int i=0;i<s.length();i++)
  {  
    if(s[i]!=t[i])
      count++;
    
      
  
  }
  cout<<count;
  return;
}


int main()
{
solve();
}