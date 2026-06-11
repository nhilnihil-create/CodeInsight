#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s,t;
  cin>>s>>t;
  string a = "abcdefghijklmnopqrstuvwxyz";
  int i,j,ans =0 ,ii,ij,c=0;
  for(i=0;i<= s.length()-t.length();i++)
  {
      for(j=0;j<t.length();j++)
      {
          ii=i;
          //ij=j;
          if(s[i+j] == t[j])
            c++;
      }
      ans = max(ans,c);
      c=0;
  }



  cout<<t.length()-ans;
  return 0;
}
