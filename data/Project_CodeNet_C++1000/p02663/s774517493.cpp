#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int bt = h1 * 60 + m1;
    int et = h2 * 60 + m2;
    int ans = et - bt - k;
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}