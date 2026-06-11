#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,i0,n) for(int i=i0;i<n;++i)

int main()
{
    int n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto& ai:a) cin >> ai;

    ll asum = accumulate(a.begin(),a.end(),ll(0));
    vector<ll> x;
    for(ll i=1,i_max=(ll)sqrt(asum);i<=i_max;++i) {
        if(asum%i == 0) {
            x.push_back(i);
            if(i*i != asum) x.push_back(asum/i);
        }
    }
    sort(x.begin(),x.end(),greater<ll>());

    for(auto xi:x) {
        vector<ll> y(n);
        rep(i,n) y[i] = a[i] % xi;
        sort(y.begin(),y.end());
        ll rsum = 0;
        rep(i,n) rsum += (xi-y[i]) % xi;
        ll sum = 0;
        rep(i,n) {
            rsum -= (xi-y[i]) % xi;
            sum += y[i];
            if(sum >= rsum) break;
        }
        if(sum <= k) {
            cout << xi << endl;
            return 0;
        }
    }

    cout << 1 << endl;
    return 0;
}