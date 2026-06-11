#include<bits/stdc++.h>

using namespace std;
int Main()
{
  string s;
  cin>>s;
  int mod =2019;
  
  long long ans=0;
  int suf =0;
  int pt= 1;
  int n = s.length();
  
   vector<int> sufar(3000);
  
   sufar[0]=1;
  
  for(int i=n-1;i>=0;i--){
    
    suf+= (s[i]-'0' )*pt;
    suf%=mod;
    pt*=10;
    pt%=mod;
    ans+= sufar[suf];
    sufar[suf]++;
       
     
  }
  
  cout<<ans;
  
  return 0;
}























// main function..
int main(){


    Main();
    
    
}
