#include <iostream>
#include <queue>
#include <set>

int main() {
    int N;
    std::cin >> N;

    std::priority_queue<std::pair<long long, long long>> que;
    for (long long i = 1; i <= N; i++) {
        long long P;
        std::cin >> P;
        que.push(std::make_pair(P, i));
    }

    std::multiset<long long> s;
    s.insert(0);
    s.insert(0);
    s.insert(N + 1);
    s.insert(N + 1);

    long long ans = 0;
    while (!que.empty()) {
        auto p = que.top();
        que.pop();

        long long P = p.first;
        long long i = p.second;

        s.insert(i);
        auto itr = s.lower_bound(i);

        long long w = *(std::prev(itr, 2));
        long long x = *(std::prev(itr, 1));
        long long y = *(std::next(itr, 1));
        long long z = *(std::next(itr, 2));

        ans += P * ((x - w) * (y - i) + (i - x) * (z - y));
    }
    std::cout << ans << "\n";
}