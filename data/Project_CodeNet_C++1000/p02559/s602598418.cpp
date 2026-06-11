#ifdef _MSC_VER
#include <__msvc_all_public_headers.hpp>
#undef min
#undef max
#include "atcoder/all"
#else
#define NDEBUG
#include <atcoder/all>
#include <bits/stdc++.h>
#endif

using namespace std;
using namespace atcoder;

int main()
{
    int n, q;
    cin >> n >> q;

    auto f = fenwick_tree<unsigned long long>(n);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        f.add(i, ai);
    }

    for (int i = 0; i < q; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            f.add(b, c);
        }
        if (a == 1) {
            cout << f.sum(b, c) << "\n";
        }
    }

    return 0;
}
