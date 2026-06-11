#include<bits/stdc++.h>
#define M 1000000007
#define pi ld(acos(-1.0))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,n) for(int i=1;i<(int)(n);i++)
#define repp(i,a,b)  for(int i=a;i<=(int)(b);i++)
#define Repp(i,a,b)  for(int i=a;i>=(int)(b);i--)
#define cs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fi first
#define se second
#define ii pair<int,int>
#define bye(x) {cout<<x;return 0;}
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    cs
    int n;cin>>n;
    vector<ll> v(n);
    for(auto &i:v) cin>>i;
    ll ans=0,t=1;
    rep(i,60) {
        ll a=0,b=0;
        rep(j,n) {
            if(v[j]&1) a++;else b++;
            v[j]>>=1;
        }
        ans+=(((a*b)%M)*t)%M;
        t<<=1;t%=M;ans%=M;
    }
    cout<<ans;
}