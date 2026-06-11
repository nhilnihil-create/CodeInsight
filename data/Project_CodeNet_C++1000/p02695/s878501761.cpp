#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll N,M,Q;
vector<ll>a,b,c,d;
ll score(const vector<ll>&A){
  ll res=0;
  for(ll i=0;i<Q;i++){
    if(A[b[i]]-A[a[i]]==c[i])res+=d[i];
  }
  return res;
}
ll dfs(vector<ll>&A){
  if(A.size()==N){
    return score(A);
  }
  ll res=0;
  ll prev_back=(A.empty()?0:A.back());
  for(ll i=prev_back;i<M;i++){
    A.push_back(i);
    res=max(res,dfs(A));
    A.pop_back();
  }
  return res;
}
int main(){
  cin>>N>>M>>Q;
  a.resize(Q),b.resize(Q),c.resize(Q),d.resize(Q);
  for(ll i=0;i<Q;i++){
    cin>>a[i]>>b[i]>>c[i]>>d[i];
    a[i]--,b[i]--;
  }
  vector<ll>A;
  cout<<dfs(A)<<endl;
}