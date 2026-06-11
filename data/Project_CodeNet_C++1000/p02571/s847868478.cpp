#include<bits/stdc++.h>
using namespace std;


int main()

{
   string s,t;
  cin>>s>>t;
  
  int ls=s.length();
  int lt=t.length();
  int ans=INT_MAX;
  for(int a=0;a<ls-lt+1;a++) 
  {
    int different=0;
    
  for(int b=0;b<lt;b++)
  {
       if(s[a+b]!=t[b])
         different++;
         
        
      
  }
    ans=min(ans,different);
  }
  cout<<ans<<endl;
}