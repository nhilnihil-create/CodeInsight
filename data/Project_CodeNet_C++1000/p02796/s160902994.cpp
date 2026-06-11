#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;


int main() {
    int N;
    cin >> N;
    vector<pair<ll,ll>> v(N);
    rep(i, N) {
        ll x,l;
        cin >> x >> l;
        v[i].first = x+l;
        v[i].second = x-l;
    }
    ll t = -1e9;
    sort(v.begin(), v.end());
    int ans = 0;
    rep(i, N) {
        if(t > v[i].second) continue;
        ans++;
        t = v[i].first;
    }
    cout << ans << endl;

}
