#include <iostream>
#include <vector>

static inline void rec(int t, int s, std::vector<std::pair<int, int>>& v, const std::vector<std::vector<int>>& tr) {
    if (v[t].second != 0) {
        return;
    }
    v[t].second = 1;
    v[t].first += s;
    s = v[t].first;
    for (const auto& tt: tr[t]) {
        rec(tt, s, v, tr);
    }
}

int main() {
    int n, q; std::cin >> n >> q;
    std::vector<std::vector<int>> t(n);
    for (int i = 0 ; i < n-1; i++) {
        int a, b; std::cin >> a >> b;
        a--; b--;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    std::vector<std::pair<int, int>> v(n, {0, 0});
    for (int i = 0; i < q; i++) {
        int p, x; std::cin >> p >> x;
        p--;
        v[p].first += x;
    }
    rec(0, 0, v, t);
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            std::cout << " ";
        }
        std::cout << v[i].first;
    }
    std::cout << std::endl;
    return 0;
}