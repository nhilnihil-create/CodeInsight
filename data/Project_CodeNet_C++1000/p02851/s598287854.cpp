#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n,k; cin>>n>>k;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    rep(i,n) a[i]%=k;
    vector<ll> b(n+1,0);
    rep(i,n) b[i+1]=(a[i]+b[i])%k;
    rep(i,n+1){
        b[i]-=i;
        b[i]%=k;
        if(b[i]<0) b[i]+=k;
    }
    //rep(i,9) cout<<b[i]<<' ';
    map<ll,ll> m;
    ll res=0;
    for(ll i=n; i>=0; i--){
        if(i<=n-k) m[b[i+k]]--;
        res+=m[b[i]];
        m[b[i]]++;

    }
    cout<<res<<endl;
    return 0;
}