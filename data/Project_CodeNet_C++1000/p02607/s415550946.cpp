#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if ((i & 1) && (x & 1))
            ans++;
    }
    cout << ans;

    return 0;
}
