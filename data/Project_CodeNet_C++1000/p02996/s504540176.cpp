/**
*    created: 12.06.2020 18:32:23
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int,int>> mp(n);
    rep(i,n) {
        //はじめがlimit, あとが所要時間
        cin >> mp[i].second >> mp[i].first;
    }
    sort(mp.begin(),mp.end());
    int sum = 0;
    bool ok = true;
    rep(i,n) {
        sum += mp[i].second;
        if (sum > mp[i].first) {
            ok = false;
            break;
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}