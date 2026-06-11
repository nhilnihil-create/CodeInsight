#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    rep(i,n) {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll all = 0;
    for (auto x : mp) {
        ll cnt = x.second;
        all += cnt*(cnt-1)/2;
    }
    rep(i,n) {
        ll ans = all - (mp[a[i]]-1);
        cout << ans << endl;
    }
    return 0;
}