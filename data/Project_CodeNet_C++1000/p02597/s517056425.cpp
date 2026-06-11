#include<bits/stdc++.h>
using namespace std;
int main()
{
  
  int n;
  cin>>n;
  string s;
  cin>>s;
  int i=0;
  int j=n-1;
  int ans=0;
  while(i<j)
  {
    if(s[i]=='R'&&s[j]=='W')
       {
           i++;
           j--;
       }
     else if(s[i]=='R')
     i++;
     else if(s[j]=='W')
     j--;
     else 
     {
         ans++;
         i++;
         j--;
     }
         
       
  }
  cout<<ans;
  return 0;
}