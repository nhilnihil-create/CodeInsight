#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    ll cnt1=0;
    rep(i,n){
        repi(j,i+1,n) if(a[i]>a[j]) cnt1++;
    }
    ll ans=(cnt1*k)%mod;
    ll cnb=k*(k-1)/2%mod;
    rep(i,n){
        ll cnt2=0;
        rep(j,n) if(a[i]>a[j]) cnt2++;
        ll t=cnt2*cnb%mod;
        ans=(ans+t)%mod;
    }
    cout<<ans;
}