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
int f(ll x) {
    int t=0;
    while(x%2==0) {
        x/=2;t++;
    }
    return t;
}
int main() {
    cs
    int n,m;cin>>n>>m;
    vector<ll> v(n);
    for(auto &i:v) cin>>i;
    ll t=f(v[0]);
    for(auto i:v) if(f(i)!=t) bye(0)
    t=1;
    for(auto i:v) {
        t*=(i/2)/__gcd(t,i/2);
        if(t>m) bye(0)
    }
    cout<<((m/t)+1)/2;
}