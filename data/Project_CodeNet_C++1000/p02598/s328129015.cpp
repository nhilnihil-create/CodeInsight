#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main() {
    int n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll l = 0, r = 1e9;
    ll x = 0;
    while(r-l>1) {
        x = (l+r)/2;
        ll times = 0;
        rep(i,n) {
            times += (a[i]-1)/x;
        }
        if (times>k) l = x;
        else r = x;
    }
    cout << r << endl;
    return 0;
}