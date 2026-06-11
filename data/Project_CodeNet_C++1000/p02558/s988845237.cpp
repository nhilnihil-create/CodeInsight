// 　　＿＿
// 　／　<＠ﾌ
//  ｜(ﾉﾉハ))
//  ﾉ从ﾟヮﾟ从
// 　ﾉ｜ｿﾉГ|つ author:hotarunx
// 〈_ﾉ^^^ヽ|
// 　~~tｧtｧ~
#include <algorithm>
#include <array>
#include <atcoder/dsu>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
using namespace atcoder;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    dsu d(n);

    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;

        if (!t) {
            d.merge(u, v);
        } else {
            cout << d.same(u, v) << "\n";
        }
    }
}
