#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int n, m, q;
vector<int> a, b, c, d;
vector<int> p;
int res = 0;

void bt() {
    if (p.size() == n) {
        int score = 0;
        for (int i = 0; i < q; i++) {
            if (p[b[i]] - p[a[i]] == c[i]) {
                score += d[i];
            }
        }
        res = max(res, score);
        return;
    }
    for (int x = 1; x <= m; x++) {
        if (!p.empty() && x < p.back()) continue;
        p.push_back(x);
        bt();
        p.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m >> q;
    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--; b[i]--;
    }
    bt();
    cout << res << "\n";

    return 0;
}