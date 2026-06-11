#include"bits/stdc++.h"
#define rep(i,n) for(ll i=0;i<n;++i)
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007

using namespace std;
typedef long long ll;

template<typename T>
T gcd(T a, T b) {
    if (a % b == 0) {
        return(b);
    }
    else {
        return(gcd(b, a % b));
    }
}

template<typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

int main(void) {
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(i,n){
        cin>>a[i];
    }
    sort(ALL(a));
    
    ll ans=0;
    rep(i,n-1){
        ans+=a[n-(i+1)/2-1];
    }
    cout<<ans;
}
