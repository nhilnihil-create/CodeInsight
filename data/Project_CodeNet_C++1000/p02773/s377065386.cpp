#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    map<string, int> tbl;
    int cnt_max = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (tbl.count(s[i])) {
            tbl[s[i]]++;
            cnt_max = max(cnt_max, tbl[s[i]]);
        } else {
            tbl[s[i]] = 1;
            cnt_max = max(cnt_max, 1);
        }
    }
    vector<string> ans(0);
    for (auto p : tbl) {
        if (p.second == cnt_max) {
            cout << p.first << endl;
        }
    }
    return 0;
}