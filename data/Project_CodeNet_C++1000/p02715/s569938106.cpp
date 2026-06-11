#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#define cs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define M 1000000007
#define rep(i,b)  for(int i=0;i<(int)(b);i++)
#define Rep(i,n) for(int i=1;i<(int)(n);i++)
#define repp(i,a,b)  for(int i=a;i<=(int)(b);i++)
#define Repp(i,a,b)  for(int i=a;i>=(int)(b);i--)
typedef long long ll;
typedef long double ld;

using namespace std;
ll power(ll a,ll b){
    ll t=1;
    while(b) {
        if(b&1) t=(t*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return t;
}
int main(){
    cs
    ll n,k,ans=0;cin>>n>>k;
    vector<ll> v(k+1);
    Repp(i,k,1) {
        v[i]=power(k/i,n);
        for(int j=i*2;j<=k;j+=i) v[i]-=v[j];
    }
    repp(i,1,k) {ans+=v[i]*i;ans%=M;}
    cout<<ans;
}