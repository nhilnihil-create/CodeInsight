#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
ll H,W,M;
ll Y[300005];
ll X[300005];
int main(){
  cin>>H>>W>>M;
  vector<P>A(M);
  for(ll i=0;i<M;i++){
  ll y,x;cin>>y>>x;
    P p(y,x);A[i]=p;
  Y[y]++;X[x]++;
  }ll ymax=0;ll xmax=0;
  for(ll i=1;i<=H;i++)
    if(ymax<Y[i])ymax=Y[i];
  for(ll i=1;i<=W;i++)
    if(xmax<X[i])xmax=X[i];
  set<ll>Symax;set<ll>Sxmax;
  for(ll  i=1;i<=H;i++)
    if(Y[i]==ymax)Symax.insert(i);
  for(ll i=1;i<=W;i++)
    if(X[i]==xmax)Sxmax.insert(i);
  ll ans=ymax+xmax;ll sum=0;
  for(ll i=0;i<M;i++){
  ll y=A[i].first;
    ll x=A[i].second;
    if(Symax.count(y) && Sxmax.count(x))
      sum++;
  }ll a=Symax.size();ll b=Sxmax.size();
  if(sum==a*b)ans--;
  cout<<ans<<endl;
  return 0;
}