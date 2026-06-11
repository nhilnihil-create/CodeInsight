#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int main() {
    using VertexId = std::uint32_t;
    using EdgeId = std::uint64_t;

    auto n = VertexId(0);
    auto m = EdgeId(0);
    std::cin >> n >> m;

    auto adjacency_list = std::vector<std::vector<VertexId>>(n, std::vector<VertexId>());

    auto in_edge_num = std::vector<VertexId>(n, VertexId(0));

    for (auto i_ = 0; i_ < m; ++i_) {
        auto source = VertexId(0);
        auto target = VertexId(0);
        std::cin >> source >> target;

        adjacency_list[source].emplace_back(target);
        in_edge_num[target]++;
    }

    auto sorted_vertex = std::vector<VertexId>();
    const auto invalid_vertex = std::numeric_limits<VertexId>::max();

    auto q = std::queue<VertexId>();
    for (auto i = 0; i < n; ++i) {
        if (in_edge_num[i] == 0) q.emplace(i);
    }

    while (!q.empty()) {
        const auto v = q.front();
        q.pop();

        in_edge_num[v] = invalid_vertex;

        sorted_vertex.emplace_back(v);

        for (const auto& target_from_v : adjacency_list[v]) {
            if (in_edge_num[target_from_v] != invalid_vertex) {
                in_edge_num[target_from_v]--;

                if (in_edge_num[target_from_v] == 0) q.emplace(target_from_v);
            }
        }
    }

    for (const auto& v : sorted_vertex) {
        std::cout << v << std::endl;
    }
    return 0;
}
