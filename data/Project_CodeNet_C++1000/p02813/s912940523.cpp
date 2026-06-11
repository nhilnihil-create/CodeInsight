#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n;
    cin >> n;
    vector<int> p(n), q(n), per(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];

    rep(i, n) per[i] = i + 1;
    int np, nq;
    int idx = 0;
    do
    {
        if (p == per)
        {
            np = idx;
        }
        if (q == per)
        {
            nq = idx;
        }
        idx++;
    } while (next_permutation(all(per)));

    cout << abs(nq - np) << '\n';

    return 0;
}
