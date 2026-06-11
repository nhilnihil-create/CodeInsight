#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll a;
  cin>>a;
  ll b;
  cin>>b;
  ll c;
  cin>>c;
  ll f=-1;
  vector<ll>vec(a);
  vector<ll>veco(0);
  for(ll i=0;i<a;i++){
    if(i==0){
      cin>>vec.at(i);
    }
    else{
      ll d;
      cin>>d;
      vec.at(i)=vec.at(i-1)+d;
      
      }
    if(vec.at(i)>c&&f==-1){
        f=max(f,i);
        
    }
    if(i==a-1&&f==-1&&vec.at(i)<=c){
      f=max(f,i+1);
    }
  }
  
  for(ll i=0;i<b;i++){
    if(i==0){
      ll e;
      cin>>e;
      veco.push_back(e);
    }
    else{
      ll e;
      cin>>e;
      veco.push_back(e+veco.at(i-1));
      
    }
    if(veco.at(i)>c){
        f=max(f,i);
        break;
      }
    if(i==b-1){
      f=max(f,i+1);
    }
  }
  
  ll x=veco.size()-1;
  for(ll i=0;i<vec.size()&&vec.at(i)<=c;i++){
    ll g=c-vec.at(i);
    if(f>i+2){
      if(f-2-i>=veco.size()){
        continue;
      }
      else if(veco.at(f-2-i)>g){
        continue;
      }
    }
      
    for(ll j=x;j>=0;j--){
      if(veco.at(j)<=g){
        f=max(i+j+2,f);
        x=j;
        break;
      }
      if(j==0){
        f=max(f,i+1);
      }
    }
  }
  cout<<f<<endl;
      
    
    
  return 0;
}

