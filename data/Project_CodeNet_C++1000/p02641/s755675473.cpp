#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void solve() {
    int x, n;
    cin >> x >> n;
    vector<int> p(101, 0);
    rep(i, n) {
        int t;
        cin >> t;
        p[t]++;
    }

    vector<int> cand;
    for (int i = 1; i <= 100; i++) {
        if (p[i] == 0) {
            cand.push_back(i);
        }
    }
    cand.push_back(0);
    cand.push_back(101);
    sort(cand.begin(), cand.end());

    int ans = 0;
    int diff = 10000;
    rep(i, cand.size()) {
        if (diff > abs(x - cand[i])) {
            ans = cand[i];
            diff = abs(x - cand[i]);
        }
    }

    cout << ans << endl;

}

int main() {
    solve();
    return 0;
}
