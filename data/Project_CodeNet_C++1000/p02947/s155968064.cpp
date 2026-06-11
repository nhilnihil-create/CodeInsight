#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {

    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    map<string, ll> sums;

    rep(i, n) {
        sort(s[i].begin(), s[i].end());
        if(sums.count(s[i]) == 0) {
            sums[s[i]] = 1;
        } else {
            sums[s[i]]++;
        }
    }

    ll ans = 0;

    for(auto itr = sums.begin(); itr != sums.end(); ++itr) {
        if(itr->second > 1) {
            ll tmp = itr->second - 1;
            ans += (tmp * (tmp + 1) / 2);
        }
    }

    cout << ans << endl;
    return 0;
}
