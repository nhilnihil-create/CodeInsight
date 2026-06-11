#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
  string s,t;
  cin>>s>>t;
  if(s==t) cout<<"0"<<endl;
  else
  {
      int cnt=0;
      for(int i=0;i<s.length();i++)
      {
          if(s[i]!=t[i]) cnt++;
      }
      cout<<cnt<<endl;
  }


   return 0;
}
