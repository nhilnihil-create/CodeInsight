#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int n, m, a, b;
long long res;
vector<vector<int>> v;
priority_queue<int> pq;
int main() {
    DAU
    cin >> n >> m;
    v.resize(m + 1);
    while (n--) {
        cin >> a >> b;
        if (a <= m)
            v[a].emplace_back(b);
    }
    for (int i = 1; i <= m; ++i) {
        for (const int& x : v[i])
            pq.emplace(x);
        if (!pq.empty())
            res += pq.top(), pq.pop();
    }
    cout << res;
    PLEC
}
