#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main(){
    ll n,k; cin>>n>>k;
    vector<ll> a(n), f(n);
    rep(i, n) cin>>a[i];
    rep(i, n) cin>>f[i];
    sort(a.begin(), a.end(), greater<ll>());
    sort(f.begin(), f.end());
    ll ng = -1, ok = 1e15;
    while(ok - ng > 1){
        ll mid = (ng + ok)/2;
        ll cnt = 0;
        rep(i, n){
            if(a[i] * f[i] > mid){
                cnt += a[i] - (mid / f[i]);
            } // just mid is ok
        }
        if(cnt > k){
            ng = mid;
        }else{
            ok = mid;
        }
    }
    cout << ok << endl;
    return 0;
}