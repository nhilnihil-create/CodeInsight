#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;
    map<char, vector<int>> index;
    REP(i, s.size()) index[s[i]].push_back(i);
    ll i = -1, a = 0;
    for (char c : t) {
        if (index.count(c) == 0) {
            cout << -1 << endl;
            return 0;
        }
        auto j = lower_bound(ALL(index[c]), i);
        if (j == index[c].end()) {
            a++;
            i = index[c][0];
        } else {
            i = *j;
        }
        i++;
    }
    cout << (ll) s.size() * a + i << endl;
}