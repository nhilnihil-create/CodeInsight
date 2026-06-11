#include <bits/stdc++.h>

using namespace std;

int lowbit(int x) { return x & -x; }

int N;
vector<pair<int, int>> edges;

int main() {
    scanf("%d", &N);
    if (N == lowbit(N)) {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    edges.emplace_back(1, 3);
    edges.emplace_back(3, 2);
    edges.emplace_back(1, N + 2);
    edges.emplace_back(N + 2, N + 3);
    edges.emplace_back(N + 3, N + 1);
    for (int i = 4; i < N; i += 2) {
        edges.emplace_back(1, i + 1);
        edges.emplace_back(i + 1, i);
        edges.emplace_back(1, N + i);
        edges.emplace_back(N + i, N + i + 1);
    }
    if (!(N & 1)) {
        int t = lowbit(N);
        edges.emplace_back(N + t, N);
        edges.emplace_back(N - t + 1, N + N);
    }
    for (const auto &i : edges) printf("%d %d\n", i.first, i.second);
}
