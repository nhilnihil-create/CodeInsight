#include <bits/stdc++.h>


using namespace std;
using ll = long long;

const ll sz = 2e6 + 10;
ll a[sz], b[sz];

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll cs = 0, tmp;
    for(ll i = 0; i < n; i++) {
        cin >> tmp;
        cs += tmp;
        a[i] = cs;
    }
    cs = 0;
    for(ll i = 0; i < m; i++) {
        cin >> tmp;
        cs += tmp;
        b[i] = cs;
    }
    ll mx = 0;
    for(ll i = 0; i < n; i++) {
        if(a[i] > k) break; 
        ll cnt = 0;
        auto it = lower_bound(b, b+m, k-a[i]) - b;
        if(it == m || b[it] > k-a[i]) it--;
        cnt += it  + 1;
        cnt += (i + 1);
        mx = max(mx, cnt);
    }
    ll mxb = 0;
    for(ll i = 0; i < m; i++) {
        if(b[i] > k) break;
        auto it = lower_bound(a, a+n, k-b[i]) - a;
        ll cnt = 0;
        if(it == n || b[it] > k-b[i]) it--;
        cnt += (i + 1);
        mxb = max(mxb, cnt);
    }
    cout << max(mx, mxb) << "\n";
    



    return 0;
}

