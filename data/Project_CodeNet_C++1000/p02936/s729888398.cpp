#include <vector>
#include <string>
#include <iostream>

using tree_t = std::vector<std::vector<int>>;

void dfs(int s, tree_t & tree, long long * counter, int * is_calculated) {
    is_calculated[s] = true;
    const auto sub_tree { tree[s] };
    for (std::size_t i = 0, elements = sub_tree.size(); i < elements; ++i) {
        const int v { sub_tree[i] };
        if (is_calculated[v]) {
            continue;
        }
        counter[v] += counter[s];
        dfs(v, tree, counter, is_calculated);
    }
}

std::string solve(int n, int q, tree_t & tree, long long * counter) {
    int * is_calculated = new int[n];
    for (int i = 0; i < n; ++i) {
        is_calculated[i] = 0;
    }
    dfs(0, tree, counter, is_calculated);
    std::string s { "" };
    for (int i = 0; i < n; ++i) {
        s += std::to_string(counter[i]) + " ";
    }
    delete[] is_calculated;
    return s;
}
 
int main() {
    int N, Q;
    std::cin >> N >> Q;

    tree_t tree = [&]() {
        tree_t v(N);
        for (int i = 0; i < N - 1; ++i) {
            int a, b;
            std::cin >> a >> b;
            v[a - 1].push_back(b - 1);
            v[b - 1].push_back(a - 1);
        }
        return v;
    }();
 
    long long * counter = new long long[N];
    for (int i = 0; i < N; ++i) {
        counter[i] = 0;
    }
    for (int i = 0; i < Q; ++i) {
        int x, p;
        std::cin >> p >> x;
        counter[p - 1] += x;
    }
 
    std::cout << solve(N, Q, tree, counter) << std::endl;
    
    delete[] counter;

    return 0;
}
