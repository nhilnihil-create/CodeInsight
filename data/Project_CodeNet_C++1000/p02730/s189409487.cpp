#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int len=s.size();
  int len1=len-1;
  int flag=0,flag1=0,flag2=0;
  int q=((len1+2)/2)-1;
  for(int k=0;k<len;k++)
  {
      if(s[k]!=s[len1-k])
      {
          flag=1;

      }
  }
  int p=(len/2)-1;
  for(int i=0;i<=p;i++)
  {
     if(s[i]!=s[p-i])
     {
         flag1=1;
     }


  }

  for(int j=q;j<=len1;j++)
  {
      if(s[j]!=s[len1-j])
      {
          flag2=1;
      }

  }



  if(flag==1 || flag1==1 || flag2==1)
  {
      cout<<"No";
  }
  else
  {
      cout<<"Yes";
  }
  return 0;


}
