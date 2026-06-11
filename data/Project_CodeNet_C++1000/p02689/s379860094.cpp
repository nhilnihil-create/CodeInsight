#include <iostream>
#include <vector>
#include <unordered_map>

using TourId = long long;

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<long long> H(N);
    for (auto&& e : H) {
        std::cin >> e;
    }
    std::unordered_map<TourId, std::vector<TourId>> adjs;
    for (long long i=0; i<N; i++) {
        adjs.insert(std::make_pair(i, std::vector<TourId>{}));
    }
    for (long long i=0; i<M; i++) {
        long long A, B;
        std::cin >> A >> B;
        adjs[A-1].push_back(B-1);
        adjs[B-1].push_back(A-1);
    }

    int count = 0;
    for (auto const& e : adjs) {
        auto const& tour_id = e.first;
        auto const& adj = e.second;
        bool is_good = true;
        for (auto const& adj_id : adj) {
            if (H[tour_id] <= H[adj_id]) {
                is_good = false;
                break;
            }
        }
        if (is_good)
            count++;
    }
    std::cout << count << std::endl;
}