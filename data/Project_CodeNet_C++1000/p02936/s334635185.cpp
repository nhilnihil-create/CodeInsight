#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
vector<vector<ll>> vec;
vector<ll> ans;
vector<bool> note;
vector<ll> p;

void dfs(ll t,ll count) {
  ans[t-1]=p[t-1]+count;
  note[t-1]=true;
  for(ll x:vec[t-1]) {
if(note[x-1]) {
continue;
}
   dfs(x,count+p[t-1]);
  }
  return ;
}
  

 
int main() {
  ll N,Q;
  cin>>N>>Q;
  note=vector<bool> (N,false);
  ans=vector<ll> (N);
 vec= vector<vector<ll>> (N,vector<ll>(0));
  for(ll i=0;i<N-1;i++) {
ll A,B;
    cin>>A>>B;
    vec[A-1].push_back(B);
    vec[B-1].push_back(A);
  }
  
  p=vector<ll> (N,0);
  for(ll i=0;i<Q;i++) {
ll P,X;
    cin>>P>>X;
    p[P-1]+=X;
  }
  
  dfs(1,0);
 for(ll x:ans) {
cout<<x<<" ";
 }
  cout<<endl;
}
  
  
  
  
  
  
  
  
  