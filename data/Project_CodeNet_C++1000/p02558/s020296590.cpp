#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

int p[N], n;

int find(int x) {
    return x == p[x] ? p[x] : p[x] = find(p[x]);
}

int main() {
    cin >> n;
    int m;
    cin >> m;
    for (int i = 1; i <= n; ++i) p[i] = i;
    for (int i = 1; i <= m; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 0) p[find(a)] = find(b);
        else {
            if (find(a) == find(b)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
    return 0;
}