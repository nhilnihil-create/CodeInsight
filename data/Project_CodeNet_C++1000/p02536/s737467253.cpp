#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ll long long

int main() {
    int n, m;
    cin >> n >> m;
    dsu uf(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        uf.merge(a, b);
    }
    int ans = 0;
    rep(i, n) {
        if (uf.leader(i) == i) ans++;
    }
    cout << ans - 1 << endl;
} 