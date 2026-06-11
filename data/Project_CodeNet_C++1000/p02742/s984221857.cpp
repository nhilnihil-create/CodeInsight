#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ll H, W;
    cin >> H >> W;

    ll ans;
    if (H == 1 || W == 1)
    {
        ans = 1;
    }
    else
    {
        ans = ((W + 1) / 2) * ((H + 1) / 2) + (W / 2) * (H / 2);
    }

    cout << ans << endl;

    return 0;
}