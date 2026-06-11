#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define mod (int)(1e9 + 7)
#define pb push_back
#define int long long
using namespace std;
typedef pair<int,int> pii;

signed main(){
  int n;
  string s;
  cin>>n>>s;

  if(s[0]=='W' || s[s.size()-1]=='W'){
    cout<<0<<endl;
    return 0;
  }

  bool hako[2*n+1];

  hako[0]=false;
  hako[s.size()-1]=true;

  int l,r;
  l=r=0;

  for(int i=1;i<s.size()-1;i++){
    if(s[i]!=s[i-1]){
      hako[i]=hako[i-1];
    }
    else{
      hako[i]=!hako[i-1];
    }
  }

  // for(int i=0;i<s.size();i++){
  //   if(hako[i]) cout<<"R";
  //   else cout<<"L";
  // }cout<<endl;

  for(int i=0;i<s.size();i++){
    if(hako[i]) r++;
    else l++;
  }

  if(l!=r){
    cout<<0<<endl;
    return 0;
  }
  l=r=0;
  int res=1;

  int n_=n;
  for(int i=1;i<n;i++){
    n_*=i;
    n_%=mod;
  }

  for(int i=0;i<s.size();i++){
    if(!hako[i]) l++;
    else{
      res*=(l-r);
      res%=mod;
      r++;
    }
  }
  cout<<(res*n_)%mod<<endl;

  return 0;
}
