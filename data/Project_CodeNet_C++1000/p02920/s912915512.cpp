#include <iostream>
#include <vector>
#include <set>

int main() {
    int N;
    std::cin >> N;

    int K = 1 << N;

    std::multiset<int> s;
    for (int i = 0; i < K; i++) {
        int S;
        std::cin >> S;
        s.insert(S);
    }

    std::vector<int> v;
    {
        auto itr = s.end();
        --itr;
        v.push_back(*itr);
        s.erase(itr);
    }

    int k = 1;
    while (!s.empty()) {
        for (int i = 0; i < k; i++) {
            auto itr = s.lower_bound(v[i]);

            if (itr == s.begin()) {
                std::cout << "No\n";
                return 0;
            }

            --itr;
            v.push_back(*itr);
            s.erase(itr);
        }
        k *= 2;
    }

    std::cout << "Yes\n";
}