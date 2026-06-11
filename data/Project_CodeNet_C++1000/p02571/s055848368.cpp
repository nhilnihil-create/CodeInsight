#include <stdio.h>
#include <iostream>
using namespace std;

int minChange(string s1,string s2)
{
 int c=0;
 for(int i=0;i<s1.length();i++)
 if(s1[i]!=s2[i])
 c++;
 
 return c;
}

int main()
{
  string s,t,temp;
  cin>>s>>t;
  int l1=s.length();
  int l2=t.length();
  int ans=l2;
  for(int i=0;i<l1-l2+1;i++)
  {
    temp=s.substr(i,l2);
    ans=min(ans,minChange(temp,t));
  }
  cout<<ans<<endl;
    return 0;
}
