#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(200001);
bitset<200001> seen;
bitset<200001> sg;

int f (int x, bool y = true) {
    if (y) {
        seen.set();
        y = false;
    } 
    seen[x] = false;
    sg[x] = false;
    int res = 1;
    for (int i = 0; i < v[x].size(); i++) {
        int tmp = v[x][i];
        if (seen[tmp]) {
            res += f (tmp, y);
            sg[tmp] = false;
        }
    }
    return res;
}

int main() {
    sg.set();
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (sg[i]) ans = max (ans, f(i));
    }
    cout << ans << endl;
}