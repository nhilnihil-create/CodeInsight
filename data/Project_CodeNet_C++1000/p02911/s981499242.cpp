#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main() {
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> p(n,k-q);
    map<ll, ll> mp;
    vector<ll> a(q);
    rep(i,q) {
        ll h;
        cin >> h;
        h--;
        mp[h]++;
    }
    rep(i,n) {
        p[i] += mp[i];
        if (p[i]>0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
