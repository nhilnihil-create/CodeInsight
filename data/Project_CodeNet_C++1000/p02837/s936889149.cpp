#include <bits/stdc++.h>
using namespace std;

int N;
int ans;
vector<vector<pair<int, bool>>> D;

void solve(int d, vector<bool> t) {
    if (d != N) {
        t.push_back(true);
        solve(d + 1, t);
        t.pop_back();
        t.push_back(false);
        solve(d + 1, t);
    } else {
        // 矛盾が生じているかのチェック
        int a = 0;
        for (int i = 0; i < N; i++) {
            if (!t[i]) continue;
            a++;
            for (auto p : D[i]) {
                if (t[p.first] != p.second) a = INT_MIN;
            }
        }
        ans = max(ans, a);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        vector<pair<int, bool>> d;
        for (int j = 1; j <= a; j++) {
            int x, y;
            cin >> x >> y;
            d.push_back(make_pair(x - 1, y));
        }
        D.push_back(d);
    }
    ans = INT_MIN;
    vector<bool> t;
    solve(0, t);
    cout << ans << endl; 
    return 0;
}
