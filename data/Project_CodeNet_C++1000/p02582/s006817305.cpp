#include<bits/stdc++.h>
using namespace std;

int main()
{
  
  string s  ; 
  
  cin>>s ; 
  
  int max_1  = INT_MIN;
  
  int count =0 ; 
  for(int i=0 ; i<s.size() ; i++ )
  {
    if(s[i] == 'R')
      count++ ; 
    else 
    {
      count =0 ; 
    }
    max_1 = max(max_1 , count) ;     
  }
  
  cout<<max_1 ; 
  
}
