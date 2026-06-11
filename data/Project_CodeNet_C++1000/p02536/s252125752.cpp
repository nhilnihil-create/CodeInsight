/**
*    author:  boutarou
*    created: 28.09.2020 18:15:31
**/

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    dsu uf(n);
    int ans = n - 1;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (!uf.same(a, b)) {
            uf.merge(a, b);
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}