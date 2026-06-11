#include <iostream>
#include "atcoder/dsu.hpp"
using namespace std;

int main()
{
    int N, Q;
    int t, u, v;

    cin >> N >> Q;

    atcoder::dsu d(N);
    for (int i = 0; i < Q; i++)
    {
        cin >> t >> u >> v;
        if (t == 0)
        {
            d.merge(u, v);
        }
        else if (t == 1)
        {
            cout << (d.same(u, v) ? 1 : 0) << endl;
        }
    }
}
