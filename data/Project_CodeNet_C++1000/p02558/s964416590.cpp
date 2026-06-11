#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int p[200005];

int root(int x) {return p[x] < 0 ? x : p[x] = root(p[x]);}

void mer(int x, int y) {
    if ((x = root(x)) == (y = root(y))) return;
    if (p[x] > p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    int n, q, t, u, v;
    cin >> n >> q;
    for (int i = 0; i < n; i++) p[i] = -1;
    while (q--) {
        cin >> t >> u >> v;
        if (t == 0) mer(u, v);
        else cout << (root(u) == root(v)) << '\n';
    }
}
