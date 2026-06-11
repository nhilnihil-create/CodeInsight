#ifdef _MSC_VER
#include <__msvc_all_public_headers.hpp>
#undef min
#undef max
#include "atcoder/all"
#else
#define NDEBUG
#include <bits/stdc++.h>
#include <atcoder/all>
#endif


using namespace std;
using namespace atcoder;

int main()
{
    int n, q;
    cin >> n >> q;

    auto ds = dsu(n);

    for (int i = 0; i < q; ++i) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            ds.merge(u, v);
        }
        if (t == 1) {
            cout << (ds.same(u, v) ? 1 : 0) << "\n";
        }
    }

    return 0;
}
