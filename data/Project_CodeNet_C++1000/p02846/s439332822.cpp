#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    vector<ll> t(2),a(2),b(2);
    rep(i,2) cin >> t[i];
    rep(i,2) cin >> a[i];
    rep(i,2) cin >> b[i];
    rep(i,2){
        a[i]*=t[i];
        b[i]*=t[i];
    }
    if (a[0]+a[1]==b[0]+b[1]){
        cout << "infinity" << endl;
        return 0;
    }
    if (a[0]+a[1]<b[0]+b[1]){
        swap(a[0],b[0]);
        swap(a[1],b[1]);
    }
    if (a[0]>b[0]){
        cout << 0 << endl;
        return 0;
    }
    ll p=b[0]-a[0],q=a[0]+a[1]-b[0]-b[1];
    ll x=p/q;
    if (p%q==0) cout << 2*x << endl;
    else cout << 2*x+1 << endl;
}