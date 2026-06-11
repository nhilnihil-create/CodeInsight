#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n; cin>>n;
    ll len=0;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
        len+=a[i];
    }
    ll tmp=0;
    ll res=1e10;
    rep(i,n){
        tmp+=a[i];
        chmin(res, abs(len-2*tmp));
    }
    cout<<res<<endl;
    return 0;
}