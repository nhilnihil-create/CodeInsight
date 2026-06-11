#include<bits/stdc++.h>
using namespace std;

int main ()
{
  string s;
  
  cin>>s;
  
  int i=0;
  
  while(s[i]=='h' && s[i+1]=='i')
  {
    i+=2;
  }
  if(i==s.length())
    cout<<"Yes";
  
  else
    cout<<"No";

  return 0;
}