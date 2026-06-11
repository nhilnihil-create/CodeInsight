#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  int i, n;
  cin>>s;
  n=s.length();
  if(n==1 || n%2!=0)
  {
    cout<<"No";
    return 0;
  }
  if(n==2)
  {
    if(s[0]=='h' && s[1]=='i')
    cout<<"Yes";
    else
    cout<<"No";
    return 0;
  }
  for(i=0;i<n-2;i++)
  {
    if(((s[i]==s[i+2]) && (s[i]!=s[i+1])) && (s[i]=='h' || s[i]=='i'))
    continue;
    else
    {
      cout<<"No";
      return 0;
    }
  }
  cout<<"Yes";
}