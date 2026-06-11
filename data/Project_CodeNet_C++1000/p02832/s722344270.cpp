#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    int now = 1;

    rep(i, n)
    {
        int a;
        cin >> a;
        if (a == now)
            ++now;
        else
            ++ans;
    }

    if (ans == n)
        ans = -1;
    cout << ans << endl;
}