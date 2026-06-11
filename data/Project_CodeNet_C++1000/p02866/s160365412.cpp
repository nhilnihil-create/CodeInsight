#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<int> d(n);
    rep(i,n) cin >> d[i];
    if(d[0]!=0){
        cout << 0 << endl;
        return 0;
    }
    sort(d.begin(), d.end());
    int mx = d[n-1];

    vector<ll> cnt(n, 0);
    rep(i,n) cnt[d[i]]++;

    if(2<=cnt[0] || cnt[0]==0){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    for(int i=1; i<=mx; i++){
        ans *= modpow(cnt[i-1],cnt[i], 998244353);
        ans %= ll(998244353);
    }

    cout << ans << endl;

}