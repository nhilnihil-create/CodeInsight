#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
ll N;
int main(){
  cin>>N;
  vector<P>A(N);
  for(ll i=0;i<N;i++){
  ll a;cin>>a;P p(a,i+1);
    A[i]=p;
  }sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  set<ll>S1;set<ll>S2;
  S1.insert(N+1);S2.insert(0);
  ll ans=0;
  for(ll i=0;i<N;i++){
  ll x=A[i].second;ll r1,r2,l1,l2;
    auto itr1=S1.upper_bound(x);
    ll a1=*itr1;r2=a1-x;
    if(a1==N+1)
      r1=0;
    else{
    auto itr2=S1.upper_bound(a1);ll a2=*itr2;
      r1=a2-a1;
    }
       auto itr3=S2.upper_bound(-x);
    ll b1=*itr3;l2=b1+x;
    if(b1==0)
      l1=0;
    else{
    auto itr4=S2.upper_bound(b1);ll b2=*itr4;
      l1=b2-b1;
    }ans+=(N-i)*(l1*r2+r1*l2);
    S1.insert(x);S2.insert(-x);
  }cout<<ans<<endl;
  return 0;
}