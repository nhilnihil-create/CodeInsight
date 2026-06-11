#include <bits/stdc++.h>

using namespace std;

bool exists(int x, int n, string s) {
    if (x * 2 > n) return false;

    unordered_map <string, set <int> > ssm;
    set <int> epy {};
    string ss;

    for (int i = 0; i < n - x + 1; i++) {
        ss = s.substr(i, x);
        if (ssm.find(ss) == ssm.end()) {
            ssm[ss] = epy;
        }
        ssm[ss].insert(i);
    }
    set <int> si;
    for (auto itr = ssm.begin(); itr != ssm.end(); itr++) {
        si = itr->second;
        if (*si.rbegin() - *si.begin() >= x) return true;
    }

    return false;
}

int main(void) {
    int n, mi, md, ma;
    string s;
    cin >> n;
    cin >> s;

    mi = 0;  // Exist
    ma = 2501;  // Not exist
    for (int i = 0; i < 100; i++) {
        md = mi + (ma - mi) / 2;
        if (exists(md, n, s)) {
            mi = md;
        } else {
            ma = md;
        }
        if (ma - mi <= 1) break;
    }
    cout << mi << endl;

    return 0;
}
