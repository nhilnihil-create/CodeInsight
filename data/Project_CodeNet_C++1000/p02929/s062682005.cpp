#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll mod=1e9+7;
  ll ans=1;
  int n;
  string s;
  cin>>n>>s;
  int vec[2*n];
  for(int i=0;i<2*n;i++){
    if(s[i]=='W'){
      vec[i]=1;
    }
    else{
      vec[i]=0;
    }
  }
  if(vec[0]==1){
    ans=0;
  }
  int nowedge=1;
  for(int i=1;i<2*n;i++){
    if((vec[i]+nowedge)%2==0){
      nowedge++;
    }
    else{
      ans*=nowedge;
      ans%=mod;
      nowedge--;
      if(nowedge<0){
        ans*=0;
      }
    }
  }
  if(nowedge!=0){
    ans=0;
  }
  for(int i=1;i<=n;i++){
    ans*=i;
    ans%=mod;
  }
  cout<<ans<<endl;
}