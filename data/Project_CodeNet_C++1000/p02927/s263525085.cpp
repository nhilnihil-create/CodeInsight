#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int M, D;
    cin >> M >> D;

    int ans = 0;
    for (int m = 4; m <= M; m++)
    {
        for (int d = 22; d <= D; d++)
        {
            int d0 = d % 10;
            int d10 = d / 10;
            if (d0 >= 2 && d10 >= 2 && d0 * d10 == m)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}