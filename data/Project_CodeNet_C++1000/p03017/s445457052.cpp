#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,a,b,c,d;
  cin>>n>>a>>b>>c>>d;
  string s;
  cin>>s;
  for(int i=a-1;i<max(c,d)-1;i++)
  {
    if(s[i]=='#' && s[i+1]=='#')
    {
      cout<<"No"<<endl;
      return 0;
    }
  }
  if(d<c && (s[d-2]=='#' || s[d]=='#'))
  {
    int t=d-1;
    while(t>=b-1)
    {
      if(s[t+1]=='.' && s[t]=='.' && s[t-1]=='.' )
      {    
        cout<<"Yes"<<endl;
        return 0;
      }
      t--;
    }
    cout<<"No"<<endl;
  }
  else cout<<"Yes"<<endl;
  return 0;
}