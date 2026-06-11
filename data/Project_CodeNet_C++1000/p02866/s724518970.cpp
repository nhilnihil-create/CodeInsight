#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,d,h=0,MOD=998244353,ans=1; cin>>N>>d;
  if(d!=0){cout<<0<<endl; return 0;}
  vector<ll>D(N);
  for(int i=1; i<N; i++){cin>>d; D[d]++; h=max(h,d);}
  if(D[0]!=0){cout<<0<<endl; return 0;}
  for(int i=1; i<h; i++){
    for(int j=0; j<D[i+1]; j++){ans*=D[i]; ans%=MOD;}
  }
  cout<<ans%MOD<<endl;
}