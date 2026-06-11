#include<bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef long double ld;
const ll MOD=1000000007;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
long long gcd(long long a,long long b){
    ll gcdmax=max(a,b);
    ll gcdmin=min(a,b);
    while(true){
        if(gcdmax%gcdmin==0)break;
        else gcdmax%=gcdmin;
        swap(gcdmin,gcdmax);
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
  ll C=1000000000;
  ll S;
  cin>>S;
  cout<<S%C<<" "<<0<<" "<<0<<" "<<S/C<<" "<<C<<" "<<min(S/C+1,C)<<endl;
}