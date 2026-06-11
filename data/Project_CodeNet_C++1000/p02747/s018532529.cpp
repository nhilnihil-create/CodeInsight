#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  if(s.size()>=2&&s.size()%2==0)
  {
  for(int i=0;i<s.size();i++)
  {
    if(i%2==0&&s[i]!='h')
    {
      cout<<"No"<<endl;
      return 0;
    }
    else if(i%2!=0&&s[i]!='i')
    {
      cout<<"No"<<endl;
      return 0;
    }
  }
    cout<<"Yes"<<endl;
  }
  else
  {
    cout<<"No"<<endl;
  }

  return 0;
}