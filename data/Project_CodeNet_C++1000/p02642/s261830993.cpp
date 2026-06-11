#include <unordered_set>
#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> A;
    std::unordered_set<int> others;
    int counts[1000001] = {0};
    for (int i = 0; i < N; ++i) {
        int a;
        std::cin >> a;
        A.push_back(a);
        others.insert(a);
        counts[a] += 1;
    }

    int ans = 0;
    for (int a : A) {
        bool del = false;
        if (counts[a] == 1) {
            others.erase(a);
            del = true;
        }
        bool ok = true;
        for (int i = 1; i * i <= a; ++i) {
            if (a % i == 0) {
                if (others.find(i) != others.end() ||
                    others.find(a / i) != others.end()) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            ++ans;
        }
        if (del) {
            others.insert(a);
        }
    }
    std::cout << ans << std::endl;
}