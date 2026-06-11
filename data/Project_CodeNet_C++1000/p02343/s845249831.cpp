#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
#define INF 100000000
#define MAXN 10010
typedef long long ll;

int n, q;
int par[MAXN], rank[MAXN];

void init(int s) {
    for (int i = 0; i < s; i++) {
        par[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) par[x] = y;
    else {
        par[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int main(void) {
    cin >> n >> q;
    init(n);
    for (int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            unite(x, y);
        } else {
            if (same(x, y)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}