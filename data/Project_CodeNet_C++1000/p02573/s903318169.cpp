#include <bits/stdc++.h>
 
#define DEBUG(x)        do { std::cerr << #x << " = " << x << std::endl;  } while(0)
#define DEBUGV(x)       for(auto e : x) { std::cerr << e << " "; }; cout << endl;
#define INFO(msg)       do { std::cerr << msg << std::endl; } while(0)
#define ll              long long
#define vi              vector<int>
#define pii             pair<int, int>
#define fori(i, s, e)   for(int i = s; i < e; i++)
#define ford(i, s, e)   for(int i = s; i >= e; i--)
 
using namespace std;

const int N = 200010;
vi link(N + 1), sz(N + 1, 1);

void init() {
    iota(link.begin(), link.end(), 0);
    sz.resize(N + 1, 1);
}

int find(int x) {
    while(x != link[x]) x = link[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(same(a, b)) return;
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    link[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int n, m;
    cin >> n >> m;

    fori(i, 0, m) {
        int x, y;
        cin >> x >> y;
        unite(x, y);
    }

    int ans = 0;
    fori(i, 1, n + 1) ans = max(sz[i], ans);
    cout << ans << endl;

    return 0;
}
