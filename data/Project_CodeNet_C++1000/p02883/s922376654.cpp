#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    ll g=gcd(a,b);
    return a/g*b;
}
ll rep_jijo(ll n,ll x){
    if(x==0) return 1;
    if(x%2==0){
        ll t=rep_jijo(n,x/2);
        return t*t;
    }
    return n*rep_jijo(n,x-1);
}

int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll>a(n);
    vector<ll>f(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> f[i];
    sort(all(a));
    sort(all(f));
    reverse(all(f));
    ll l = -1;
    ll r = 1e12;
    while(1<r-l){
        ll mid =(l+r)/2;
        ll sum=0;
        rep(i,n){
            sum += max(0ll,a[i]-mid/f[i]);
        }
        if(sum<=k) r=mid;
        else l=mid;
    }
    cout << r << endl;
    return 0;
}