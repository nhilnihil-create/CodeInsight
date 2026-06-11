// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

// --------------------------------------------------------------------------------

void solve()
{
    int n, q;
    cin >> n >> q;
    dsu d(n);
    rep(i, q)
    {
        int t, u, v;
        cin >> t >> u >> v;
        if (t)
        {
            if (d.same(u, v))
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else
        {
            d.merge(u, v);
        }
    }
}

// --------------------------------------------------------------------------------

int main()
{
    // srand((unsigned)time(NULL));
    // int bt = clock();
    solve();
    // double et = 1.0 * (clock() - bt) / CLOCKS_PER_SEC;
    // printf("Execution Time: %.4lf sec\n", et);
    return 0;
}