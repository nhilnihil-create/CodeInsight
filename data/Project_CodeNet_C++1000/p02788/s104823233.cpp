#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair <ll,ll> P;

int main(){
  ll n,d,a;
  cin>>n>>d>>a;
  P xh[200005];
  rep(i,n) cin>>xh[i].first>>xh[i].second;
  sort(xh,xh+n);
  ll x[200005],h[200005];
  rep(i,n){
    x[i]=xh[i].first;
    h[i]=xh[i].second;
  }
  vector<ll> sum(n+1,0);
  ll att_cnt=0;
  rep(i,n){
    if(i>0) sum[i]+=sum[i-1];
    h[i]-=sum[i];
    if(h[i]>0){
      ll att=(h[i]+a-1)/a*a;
      sum[i]+=att;
      att_cnt+=(h[i]+a-1)/a;
      sum[upper_bound(x,x+n,x[i]+2*d)-x]-=att;
    }
  }
  cout<<att_cnt<<endl;
  return 0;
}