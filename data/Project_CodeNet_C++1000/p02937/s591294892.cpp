#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    std::vector<std::vector<int>> v(26);
    for (int i = 0; i < s.size(); i++) {
        v[s[i] - 'a'].push_back(i + 1);
    }

    long long ans = 0;
    int now = 0;
    for (int i = 0; i < t.size(); i++) {
        int k = t[i] - 'a';
        if (v[k].empty()) {
            std::cout << "-1\n";
            return 0;
        }

        auto it = std::upper_bound(v[k].begin(), v[k].end(), now);
        if (it == v[k].end()) {
            ans += s.size();
            now = v[k].front();
        }
        else {
            now = *it;
        }
    }
    ans += now;

    std::cout << ans << "\n";
}