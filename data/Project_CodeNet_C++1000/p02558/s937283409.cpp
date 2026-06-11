// https://atcoder.jp/contests/practice2/tasks/practice2_a?lang=ja

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main()
{
    long n, q;
    cin >> n >> q;

    dsu d(n);

    for (long i = 0; i < q; ++i)
    {
        long t, u, v;
        cin >> t >> u >> v;
        if (t == 0)
        {
            d.merge(u, v);
        }
        else
        {
            cout << (d.same(u, v) ? 1 : 0) << endl;
        }
    }
    return 0;
}