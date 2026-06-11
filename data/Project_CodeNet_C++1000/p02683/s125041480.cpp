#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,M,X;
  cin>>N>>M>>X;
  vector<vector<ll>>A(N,vector<ll>(M+1));
  for(ll i=0;i<N;i++){
    for(ll j=0;j<M+1;j++){
      cin>>A[i][j];
    }
  }

  ll ans=1e+9;
  for(ll bit=0;bit<(1<<N);bit++){
    vector<ll>alg(M+1,0);
    ll flag=1;
    ll money=0;
    for(ll i=0;i<N;i++){
      if(bit&(1<<i)){
        money+=A[i][0];
        for(ll j=1;j<M+1;j++){
          alg[j]+=A[i][j];
          
          //cout<<"A"<<A[i][0]<<endl;
        }
      }
    }
    //cout<<"money"<<money<<endl;
    for(ll j=1;j<M+1;j++){
      if(alg[j]<X)flag=-1;
    }
    if(flag==1){
      ans=min(ans,money);
    }
  }
  if(ans==1e+9){
    cout<<-1<<endl;
    return 0;
  }
  cout<<ans<<endl;
}