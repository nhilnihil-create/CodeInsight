#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct s {
    int a, b, c, d;
};

int n, m, q;
vector<s> v;
vector<int> a(10);

uint64_t solve(int idx) {
    uint64_t res = 0;
    if (idx == n) {
        for (int i = 0; i < q; ++i) {
            if (a[v[i].b] - a[v[i].a] == v[i].c) {
                res += v[i].d;
            }
        }
        return res;
    }
    for (int i = 1; i <= m; ++i) {
        if (idx > 0 && a[idx - 1] > i) continue;
        a[idx] = i;
        res = max(res, solve(idx + 1));
    }
    return res;
}

int main() {
    cin >> n >> m >> q;
    v.reserve(q);
    v.resize(q);
    for(size_t i = 0; i < q; ++i) {
        cin >> v[i].a >> v[i].b >> v[i].c >> v[i].d;
        --v[i].a;
        --v[i].b;
    }
    cout << solve(0);
    return 0;
}