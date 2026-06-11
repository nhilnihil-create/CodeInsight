#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

int main()
{
    size_t N, Q;
    cin >> N >> Q;
    atcoder::fenwick_tree<long long> ft(N + 1);

    long long a;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> a;
        ft.add(i, a);
    }

    for (size_t i = 0; i < Q; i++)
    {
        int t;
        cin >> t;
        if (t == 0)
        {
            int p;
            long long x;
            cin >> p >> x;
            p++;
            ft.add(p, x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l++;
            r++;
            cout << ft.sum(l, r) << endl;
        }
    }
}
