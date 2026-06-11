#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int p, q, r;
    cin >> p >> q >> r;
    int ans = min(p + q, min(q + r, r + p));
    cout << ans << endl;
}