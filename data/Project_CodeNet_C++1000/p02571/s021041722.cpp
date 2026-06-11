#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
  int t,n,i,j,k,l;
  string s,s1;
  cin>>s;
  cin>>s1;
  n=s.size();int m=s1.size();
  int min1=1e6;
  for(i=0;i<=(n-m);i++)
  { l=0;
    for(j=0;j<m;j++)
    {
      if(s[i+j]!=s1[j]) l++;
    }
    min1=min(min1,l);
  }
  cout<<min1;
}