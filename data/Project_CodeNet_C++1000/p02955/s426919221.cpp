#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, k;
    cin>>n>>k;
    vector<ll> as(n);
    ll s = 0;
    rep(i, n) {
        cin>>as[i];
        s += as[i];
    }

    vector<ll> div;
    for (int i = 1; i * i <= s; ++i) {
        if (s % i == 0) {
            div.push_back(i);
            if (i * i != s) div.push_back(s / i);
        }
    }

    sort(div.rbegin(), div.rend());
    ll ans = 0;
    for (auto d : div) {
        vector<ll> bs(n);
        copy(as.begin(), as.end(), bs.begin());
        rep(i, n) bs[i] %= d;
        sort(bs.rbegin(), bs.rend());
        ll s = 0;
        rep(i, n) s += bs[i];

        ll cnt = 0;
        rep(i, n) {
            s -= bs[i];
            s -= d - bs[i];
            cnt += d - bs[i];
            if (s == 0 && cnt <= k) {
                cout<<d<<endl;
                return 0;
            }
        }
    }
    cout<<1<<endl;
}