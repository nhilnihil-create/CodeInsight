#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s,t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();
    vector<vector<int>> a(26);
    for (int i = 0; i < n; i++) {
        int itr = s[i] - 'a';
        a[itr].push_back(i);
    }

    ll ans = 0;
    ll rep = 0;
    ll cur = -1;
    bool flag = true;
    for (int i = 0; i < m; i++) {
        int id = t[i] - 'a';
        if(a[id].empty()) {
            flag = false;
            break;
        }

        int nxt = upper_bound(a[id].begin(), a[id].end(), cur) - a[id].begin();
        if(nxt == a[id].size()) {
            cur = a[id][0];
            rep++;
        } else {
            cur = a[id][nxt];
        }
    }
    if(!flag) {
        cout << -1 << '\n';
        return 0;
    }
    ans = n * rep + cur + 1;
    cout << ans << '\n';
}