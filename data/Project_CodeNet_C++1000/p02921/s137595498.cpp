#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  string s,t;
  int cnt=0;
  
  cin>>s>>t;
  rep(i,3)
    if(s[i]==t[i])
      cnt++;
  cout<<cnt<<endl;
    
  return 0;
}