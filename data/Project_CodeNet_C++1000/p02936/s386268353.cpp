#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll=long long;
 
vector<ll> t[200005];
vector<ll> v(200005,0);
 
void dfs(ll i,ll j){
  for(int k:t[i]){
    if(k==j) continue;
    v[k]+=v[i];
    dfs(k,i);
  }
}
 
int main(){
  int N,Q,A,B,P,X; cin>>N>>Q;
  
  REP(i,N-1){
    cin>>A>>B;
    t[A].push_back(B);
    t[B].push_back(A);
  }
  
  REP(i,Q){
    cin>>P>>X;
    v[P]+=X;
  }
  
  dfs(1,0);
  REP(i,N) cout<<v[i+1]<<" ";
}