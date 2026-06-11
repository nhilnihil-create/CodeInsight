#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,ll> pll;

int n;
ll d,a;
ll x[200001],h[200001],s[200002];
pll xh[200001];
int main(){
    cin>>n>>d>>a;
    rep(i,n){
        cin>>x[i]>>h[i];
        xh[i]={x[i],h[i]};
    }
    sort(xh,xh+n);
    rep(i,n) x[i]=xh[i].first,h[i]=xh[i].second;
    ll cnt=0;
    int l=0,r=0,px;
    ll cur=0;
    while(l<n){
        px=lower_bound(x,x+n,x[l]-d*2)-x;
        cur+=-s[px];
        ll nx=max(0ll,(h[l]+a-1)/a-cur);
        cnt+=nx;
        s[l+1]=s[l]+nx;
        cur=s[l+1];
        ++l;
    }
    cout<<cnt<<endl;
    return 0;
}
