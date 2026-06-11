#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

#define ll long long
const ll mod = 1000000007;

struct UnionFind {
    std::vector<int> d;
    UnionFind(int n=0): d(n, -1) {}
    int find(int x) {
        if(d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return false;
        if(d[x] > d[y]) std::swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y);}
    int size(int x) { return -d[find(x)];}
};

int main()
{
    int n, m;
    std::cin >> n >> m;
    UnionFind uf(n);
    for(int i=0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        --a; --b;
        uf.unite(a, b);
    }
    int ans = 0;
    for(int i=0; i < n; i++) ans = ans > uf.size(i) ? ans : uf.size(i);
    std::cout << ans << std::endl;
}