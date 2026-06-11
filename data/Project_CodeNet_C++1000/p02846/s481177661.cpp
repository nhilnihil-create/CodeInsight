#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll t[2]; cin >> t[0] >> t[1];
    ll a[2]; cin >> a[0] >> a[1];
    ll b[2]; cin >> b[0] >> b[1];

    ll mid = t[0] * (a[0] - b[0]);
    ll last = t[0] * (a[0] - b[0]) + t[1] * (a[1] - b[1]);

    if (last == 0) { // t1 + t2 秒後の距離が同じなら無限に出会う
        cout << "infinity" << endl;
        return 0;
    }
    if (((mid > 0) ^ (last > 0)) == 0) { // t1 + t2 秒経っても追いつけない
        cout << 0 << endl;
        return 0;
    }

    mid = abs(mid), last = abs(last);

    ll ans = (mid / last) * 2LL + 1;
    if (mid % last == 0) ans--;
    cout << ans << endl;
    return 0;
}
