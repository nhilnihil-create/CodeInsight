#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin >> x;
    int ans = -1;
    if (x <= 599)
        ans = 8;
    else if (x <= 799)
        ans = 7;
    else if (x <= 999)
        ans = 6;
    else if (x <= 1199)
        ans = 5;
    else if (x <= 1399)
        ans = 4;
    else if (x <= 1599)
        ans = 3;
    else if (x <= 1799)
        ans = 2;
    else
        ans = 1;
    cout << ans;

    return 0;
}
