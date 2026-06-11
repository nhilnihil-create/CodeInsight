#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  if(s.length()>3)
  {
    for(int i=0;i<3;i++)
    {
      cout<<s[i];
    }
    cout<<endl;
  }
  else
  {
    cout<<s<<endl;
  }
  return 0;
}