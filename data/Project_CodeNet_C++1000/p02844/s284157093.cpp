#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<vector<int>> ind(10, vector<int>());

bool check(int x) {
    int a, b, c;
    c = x % 10; x /= 10;
    b = x % 10; x /= 10;
    a = x;
    // abc
    auto it = upper_bound(ind[a].begin(), ind[a].end(), -1);
    if (it == ind[a].end()) return false;
    it = upper_bound(ind[b].begin(), ind[b].end(), *it);
    if (it == ind[b].end()) return false;
    it = upper_bound(ind[c].begin(), ind[c].end(), *it);
    if (it == ind[c].end()) return false;


    return true;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    rep(i, n) {
        ind[s[i] - '0'].push_back(i);
    }

    int ans = 0;
    rep(i, 1000) {
        if (check(i)) {
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
