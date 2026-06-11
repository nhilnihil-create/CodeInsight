#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
ll repeatsquaring(ll N,ll M,ll P){
  if(M==0)return 1;
  if(M%2==0){
    ll t=repeatsquaring(N,M/2,P);
    return t*t%P;
  }
  return M*repeatsquaring(N,M-1,P);
}
int main(){
  ll N;
  cin>>N;
  vector<ll>A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  ll ans=0;
  for(int i=0;i<60;i++){
    ll one=0;
    for(int j=0;j<N;j++){
      if(A[j]>>i&1)one++;
    }
    ll zero=N-one;
    ll now=zero*one%MOD;
    for(int j=0;j<i;j++)now=now*2%MOD;   
    ans+=now;
    ans=ans%MOD;
  }
  cout<<ans<<endl;
}