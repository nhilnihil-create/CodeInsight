#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int64_t H, W;
    int64_t ans;
    cin >> H >> W;

    if (H == 1 || W == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    if (H * W % 2 == 1)
    {
        ans = (H * W + 1) / 2;
        cout << ans << endl;
    }
    else
    {
        ans = (H * W) / 2;
        cout << ans << endl;
    }
}
