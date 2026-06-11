/**
*    created: 12.06.2020 17:42:06
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    vector<int> c, m;
    rep(i,n-1) {
        if (s[i] == 'R' && s[i+1] == 'L') c.push_back(i);
        if (s[i] == 'L' && s[i+1] == 'R') m.push_back(i);
    }
    m.push_back(n-1);
    vector<int> ans(n); //答え格納
    int l = c.size();
    rep(i,l) {
        int cnt;
        if (i == 0) cnt = m[i] + 1;
        else cnt = m[i] - m[i-1];

        if (cnt % 2 == 0) {
            ans[c[i]] = cnt / 2;
            ans[c[i]+1] = cnt / 2;
        }
        else {
            if (m[i] % 2 == c[i] % 2) {
                ans[c[i]] = cnt / 2 + 1;
                ans[c[i]+1] = cnt / 2;
            }
            else {
                ans[c[i]] = cnt / 2;
                ans[c[i]+1] = cnt / 2 + 1;
            }                            
        }
    }
    rep(i,ans.size()) {
        if (i == 0) cout << ans[i];
        else cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}