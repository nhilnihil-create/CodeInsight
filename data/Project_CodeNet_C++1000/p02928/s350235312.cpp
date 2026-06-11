#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e13;
const int mod = 1e9+7;
#define ll long long
signed main() {
    int n,k;
    cin >> n>>k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int cnt =0;
    rep(i,n) {
        FOR(j,i+1,n) {
            if(a[i]>a[j]) {
                cnt++;
            }
        }
    }
    int ans = cnt*k;
    ans %=mod;
    cnt=0;
    rep(i,n) {
        rep(j,n) {
            if(a[i]<a[j]) {
                cnt++;
            }
        }
    }
    int tmp = k*(k-1)/2;
    tmp %= mod;
    tmp *= cnt;
    tmp %= mod;
     ans += tmp;
    cout << ans%mod << endl;



  return 0;
}

