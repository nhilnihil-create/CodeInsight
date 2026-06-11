#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
typedef long long ll;

int main()
{
    ll N, D;
    cin >> N >> D;
    ll ans(0);
    for (ll i = 0; i < N; ++i)
    {
        ll X, Y;
        cin >> X >> Y;
        if (X * X + Y * Y <= D * D)
        {
            ++ans;
        }
    }
    cout << ans << endl;
}
