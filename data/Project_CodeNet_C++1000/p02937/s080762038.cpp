#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;



int main() {
    string s, t;
    cin >> s >> t;
    map<char, vector<int>> mp;
    rep(i, s.size()) {
        mp[s[i]].push_back(i+1);
    }
    long long ans = 0;
    int p = 0;
    rep(i, t.size()) {
        if (!mp[t[i]].size()) {
            ans = -1;
            break;
        }
        auto it = upper_bound(mp[t[i]].begin(), mp[t[i]].end(), p);
        if (it == mp[t[i]].end()) {
            ans += s.size() - p + mp[t[i]][0];
            p = mp[t[i]][0];
        } else {
            ans += *it - p;
            p = *it;
        }
    }
    cout << ans << endl;
    return 0;
}