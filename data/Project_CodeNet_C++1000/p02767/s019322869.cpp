// https://atcoder.jp/contests/abc156/tasks/abc156_c

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    long ans = (100 * 100) * 100 + 10;
    for (int p = 1; p < 100; p++)
    {
        int s = 0;
        for (int i = 0; i < n; i++)
            s += (x[i] - p) * (x[i] - p);

        if (ans > s)
            ans = s;
    }
    cout << ans << '\n';
    return 0;
}
