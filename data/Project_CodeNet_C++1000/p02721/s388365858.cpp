#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    vector<int> lmax(n + 2, 0);
    vector<int> rmax(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        char ch = s[i - 1];
        lmax[i] = max(lmax[i], lmax[i - 1]);
        if (ch == 'o') lmax[i] = max(lmax[i] , 1);
        if (i >= c + 1 && ch == 'o') lmax[i] = max(lmax[i], lmax[i - c - 1] + 1);
    }
    for (int i = n; i > 0; --i) {
        char ch = s[i - 1];
        rmax[i] = max(rmax[i], rmax[i + 1]);
        if (ch == 'o') rmax[i] = max(rmax[i], 1);
        if (i + c + 1 <= n && ch == 'o') rmax[i] = max(rmax[i], rmax[i + c + 1] + 1);
    }
    map<pair<int, int>, vector<int>> f;
    for (int i = 1; i <= n; ++i) if (s[i - 1] == 'o') {
        int lef = (i >= c + 1 ? lmax[i - c - 1] : 0);
        int rig = (i + c + 1 <= n ? rmax[i + c + 1] : 0);
        // cout << i << ' ' << lef << ' ' << rig << endl;
        if (lef + rig + 1 == k) {
            f[make_pair(lef, rig)].push_back(i);
        }
    }
    vector<int> ans;
    for (auto it : f) if (it.second.size() == 1) {
        ans.push_back(it.second[0]);
    }
    sort(ans.begin(), ans.end());
    for (auto v : ans) cout << v << '\n';
}