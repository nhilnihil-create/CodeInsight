#include <iostream>
#include <vector>
#include <set>
using i64 = long long;

int main() {
    int h, w, m;
    std::cin >> h >> w >> m;
    std::vector<int> rows(h);
    std::vector<std::vector<int>> bs(w);
    for (int i = 0; i < m; i++) {
        int p, q;
        std::cin >> p >> q;
        --p; --q;
        rows[p]++;
        bs[q].push_back(p);
    }

    std::multiset<int> s;
    for (const int e : rows) s.insert(e);

    int ret = 0;
    for (int i = 0; i < w; i++) {
        const int base = bs[i].size();
        for (const int x : bs[i]) {
            const int t = base + rows[x] - 1;
            if (t > ret) ret = t;
            s.erase(s.find(rows[x]));
        }
        if (!s.empty()) {
            const int t = base + *s.rbegin();
            if (t > ret) ret = t;
        }
        for (const int x : bs[i]) s.insert(rows[x]);
    }

    std::cout << ret << std::endl;

    return 0;
}
