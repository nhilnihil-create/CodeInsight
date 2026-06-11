#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  int ans=1;
  cin>>s;
  for(int i=0;i<s.size();i++)
  {
    if(s.at(i)==s.at(s.size()-i-1))
    {
      if(i<s.size()/2)
      {
        if(s.at(i)!=s.at(s.size()/2-1-i))
        {
          ans=0;
          break;
        }
      }
      else if(i>s.size()/2)
      {
        if(s.at(i)!=s.at(s.size()*3/2-i))
        {
          ans=0;
          break;
        }
      }
    }
    else
    {
      ans=0;
      break;
    }
  }
  if(ans==1)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}