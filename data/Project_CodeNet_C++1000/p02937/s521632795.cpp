#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    
    vector<int> s_cnt(26, 0), t_cnt(26, 0);
    rep(i, s.size()) s_cnt[s[i] - 'a'] = 1;
    rep(i, t.size()) t_cnt[t[i] - 'a'] = 1;
    rep(i, 26) {
        if (t_cnt[i] && !s_cnt[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    vector<vector<int>> s_basyo(26);
    rep(i, s.size()) s_basyo[s[i] - 'a'].push_back(i);
    long long ans_0 = 0;
    long long ans_1 = -1;
    rep(i, t.size()) {
        auto iter = upper_bound(s_basyo[t[i] - 'a'].begin(), s_basyo[t[i] - 'a'].end(), ans_1);
        if (iter ==  s_basyo[t[i] - 'a'].end()) {
            ++ans_0;
            ans_1 = *s_basyo[t[i] - 'a'].begin();
        } else {
            ans_1 = *iter;
        }
    }
    cout << ans_0 * s.size() + ans_1 + 1 << endl;
}
