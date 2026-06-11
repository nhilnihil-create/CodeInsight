#include<bits/stdc++.h>
#define M 1000000007
#define pi ld(acos(-1.0))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,n) for(int i=1;i<(int)(n);i++)
#define repp(i,a,b)  for(ll i=a;i<=(ll)(b);i++)
#define Repp(i,a,b)  for(int i=a;i>=(int)(b);i--)
#define cs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fi first
#define se second
#define ii pair<int,int>
#define bye(x) {cout<<x;return 0;}
typedef long long ll;
typedef long double ld;
using namespace std;
ll power(ll a,ll b) {
    ll t=1;
    while(b) {
        if(b&1) t=(t*a)%M;
        b>>=1;a=(a*a)%M;
    }
    return t;
}
void solve(ll n,ll r) {
    if(n<0||r<0) {cout<<0;return;}
    ll ans=1;
    repp(i,1,r) {
        ans=(ans*n)%M;
        n--;
    }
    repp(i,1,r) {
        ans=(ans*power(i,M-2))%M;
    }
    cout<<ans;
}
int main() {
    cs
    int x,y;cin>>x>>y;
    if((x+y)%3) bye(0)
    ll a=(2*y-x)/3,b=y-2*a;
    solve(a+b,min(a,b));
}