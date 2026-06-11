#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// O(\sqrt{n})
vector<ll> divisor(ll n){
    vector<ll> res;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            if(i != n / i) res.push_back(n / i);
        }
    }
    return res;
}


int main(void){
    ll n; cin >> n;
    ll k; cin >> k;
    vector<ll> a(n);

    ll sum = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    vector<ll> ds = divisor(sum);

    // 各 d \in ds について調べていく
    ll len = ds.size();
    ll ans = 0;
    for(ll i = 0; i < len; i++){
        ll d = ds[i];

        vector<ll> rs(n);
        for(ll j = 0; j < n; j++){
            rs[j] = a[j] % d;
        }
        sort(rs.begin(), rs.end());

        vector<ll> rui1(n + 1);
        vector<ll> rui2(n + 1);
        rui1[0] = 0;
        rui2[0] = 0;
        for(ll j = 0; j < n; j++){
            rui1[j + 1] = rui1[j] + rs[j];
            rui2[j + 1] = rui2[j] + (d - rs[j]);
        }

        ll tms = 1000010000;
        for(ll l = 0; l < n; l++){
            ll tms1 = rui1[l] - rui1[0];
            ll tms2 = rui2[n] - rui2[l];
            // cout << tms1 << " " << tms2 << endl;
            tms = min(tms, max(tms1, tms2));
        }
        if(tms <= k){
            ans = max(ans, d);
        }
    }
    cout << ans << endl;
    return 0;
}