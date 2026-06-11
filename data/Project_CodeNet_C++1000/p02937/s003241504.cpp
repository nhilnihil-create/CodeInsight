#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

string s, t;
vector<int> idx[28];

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> s >> t;
    rep(i, s.size()) idx[s[i]-'a'].pb(i);
    int ans = 0;
    int now = -1;
    rep(i, t.size()) {
        int ti = t[i]-'a';
        if (idx[ti].size()==0) {
            cout << -1 << endl;
            exit(0);
        }
        auto it = upper_bound(idx[ti].begin(), idx[ti].end(), now);
        if (it!=idx[ti].end()) now = *it;
        else {
            ans += s.size();
            now = idx[ti][0];
        }
    }
    cout << ans+now+1 << endl;
}