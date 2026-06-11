
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1e18;


int main() {
  ll n,m,k;
  cin>>n>>m>>k;
  vector<ll> a(n);
  vector<ll> b(m);
  vector<ll> A(n+1);
  vector<ll> B(m+1);
  A[0]=0;B[0]=0;
  ll l1=0,l2=0;
  rep(i,n){
    cin>>a[i];
    A[i+1]=A[i]+a[i];
    if (A[i+1]<=k)l1=i;
  //  cout<<"k"<<k<<" "<<A[i+1]<<" "<<l1<<endl;
  }
  rep(i,m){
    cin>>b[i];
    B[i+1]=B[i]+b[i];
    if (B[i+1]<=k)l2=i;
  }
  ll ans=0;
//  cout<<l1<<endl;
  rep(i,l1+2){
    ll rest=k-A[i];
    ll id=upper_bound(B.begin(),B.end(),rest)-B.begin();
  //  cout<<"i"<<i<<"id"<<id<<endl;
    ans=max(ans,i+id-1);
  }


cout<<ans;


}
