#include<bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef long double ld;
const ll MOD=1000000007;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define change(a,b) do{ll c=a; a=b; b=c;}while(0)
long long gcd(long long a,long long b){
    ll gcdmax=max(a,b);
    ll gcdmin=min(a,b);
    while(true){
        if(gcdmax%gcdmin==0)break;
        else gcdmax%=gcdmin;
        change(gcdmin,gcdmax);
    }
    return gcdmin;
}
ll powerup(ll N,ll P,ll M){
    if(P==0)return 1;
    else if(P%2==0){
        ll t=powerup(N,P/2,M);
        return t*t%M;
    }
    else return N*powerup(N,P-1,M)%M;
}
int main()
{
  ll N,K;
  cin>>N>>K;
  ll A[2020]={0};
  rep(i,N) cin>>A[i];
  ll ans=0;
  rep(i,N){
    rep(j,N){
      if(j<i&&A[i]>A[j])ans=(ans+K*(K-1)/2)%MOD;
      else if(j>i&&A[i]>A[j])ans=(ans+K*(K+1)/2)%MOD;
    }
  }
  cout<<ans<<endl;
}
