#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    string s, t; cin >> s >> t;
    vector<vector<int>> order(26);
    REP(i, 0, s.size()) order[s[i] - 'a'].push_back(i);

    int cnt = 0, idx = -1;
    REP(i, 0, t.size()) {
        int cur = t[i] - 'a';
        if (order[cur].size() == 0) {
            cout << -1 << endl;
            return 0;
        }
        auto itr = upper_bound(ALL(order[cur]), idx);
        if (itr != order[cur].end()) {
            idx = *itr;
        } else {
            idx = order[cur].front();
            cnt++;
        }
    }

    cout << (ll)cnt * s.size() + idx + 1 << endl;
    return 0;
}