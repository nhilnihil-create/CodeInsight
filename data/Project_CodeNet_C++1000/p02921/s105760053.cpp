#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s1,s2;
  int count=0;
  cin>>s1>>s2;
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      if(i==j)
      {
        if(s1[i]==s2[j])
        {
          count++;
        }
      }
    }
  }
  cout<<count<<endl;
} 