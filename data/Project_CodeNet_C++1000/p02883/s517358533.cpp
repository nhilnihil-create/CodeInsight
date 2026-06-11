#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), f(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> f[i];
    }
    sort(a.begin(), a.end());
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());
    ll l = -1, r = 1e+12;
    while(l + 1 < r){
        ll m = (l + r) / 2;
        ll cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += max(0LL, a[i] - m / f[i]);
        }
        if(cnt <= k){
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;
    return 0;
}