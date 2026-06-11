#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> data;

    UnionFind() = default;

    explicit UnionFind(size_t sz) : data(sz, -1) {}

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y)
            return false;
        if(data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int find(int k) {
        if(data[k] < 0)
            return (k);
        return data[k] = find(data[k]);
    }

    int size(int k) { return -data[find(k)]; }

    bool same(int x, int y) { return find(x) == find(y); }
};

int main() {
    cout << fixed << setprecision(0);

    int N, M;
    cin >> N >> M;
    UnionFind uf(N);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        uf.unite(a - 1, b - 1);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans = max(ans, uf.size(i));
    }

    cout << ans << endl;

    return 0;
}