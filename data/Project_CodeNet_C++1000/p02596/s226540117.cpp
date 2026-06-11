#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;
    int n = 7 % k;
    for (int i = 1; i <= k; i++)
    {
        if (n == 0)
        {
            cout << i;
            return 0;
        }
        n = (n * 10 + 7) % k;
    }
    cout << -1;

    return 0;
}
