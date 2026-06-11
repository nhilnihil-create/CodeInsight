#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,M;
  cin>>N>>M;
  vector<ll> vec(N,-1);
  for(ll i=0;i<M;i++) {
ll s,c;
    cin>>s>>c;
    if(vec[s-1]!=-1&&vec[s-1]!=c) {
cout<<-1<<endl;
      return 0;
    }
   
   vec[s-1]=c;
  }
 
  if(N==1&&M==0) {
cout<<0<<endl;
    return 0;
  }
  if(vec[0]==0) {
if(N==1) {
cout<<0<<endl;
  return 0;
}
    else {
cout<<-1<<endl;
    return 0;
    }
  }
  
  for(ll i=0;i<N;i++) {
if(vec[i]==-1) {
if(i==0) {
cout<<1;
}
  else {
cout<<0;
  }
}
    else {
cout<<vec[i];
    }
  }
  
  
  cout<<endl;
}
  
  
  
  
  
 
