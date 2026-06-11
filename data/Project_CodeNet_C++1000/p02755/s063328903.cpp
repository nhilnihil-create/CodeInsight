#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 10 * b;
    while (ans < 1010)
    {
        if (int(ans * 0.08) == a && int(ans * 0.1) == b)
            break;
        ++ans;
    }
    if (ans == 1010)
        cout << -1 << endl;
    else
        cout << ans << endl;
}