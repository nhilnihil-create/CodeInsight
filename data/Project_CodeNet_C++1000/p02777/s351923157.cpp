#include<bits/stdc++.h>

using namespace std;

int main(){
  string s,t;
  cin>>s>>t;
  map<string  , int  > mp;
  int a,b;
  cin>>a>>b;
  mp[s]=a;
  mp[t]= b;
  string tt;
  cin>>tt;
  mp[tt] -=1;
  cout<<mp[s]<<" "<<mp[t]<<endl;
  
  
  
  
}