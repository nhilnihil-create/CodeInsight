#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
  string s;
  string t;
  
  cin>>s>>t;
  
  int size_1=s.length();
  int size_2=t.length();
  int ans=2000;
  int sen=0;
  
  for(int i=0;i<=size_1-size_2;i++)
  {
    sen=0;
    for(int j=0;j<size_2;j++)
    {
      if(s[i+j]!=t[j])
      {
        sen++;
      }
    }
    ans=min(ans,sen);
  }
  
  cout<<ans<<endl;
  
  return 0;
}