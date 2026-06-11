#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];
    vector<int> r(n);
    rep(i, n) r[i] = i + 1;
    int cntP = 0, cntQ = 0, cnt = 0;
    do
    {
        cnt++;
        if (p == r)
            cntP = cnt;
        if (q == r)
            cntQ = cnt;
    } while (next_permutation(r.begin(), r.end()));
    cout << abs(cntP - cntQ) << endl;
    return 0;
}