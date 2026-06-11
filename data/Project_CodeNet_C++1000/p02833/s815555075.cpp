#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (ll i = (ll)(start); i < (ll)(n); ++i)
static const int INFTY = (1 << 30);
ll N, M;
void func()
{
    cin >> N;
    ll ans(0);
    // a[0] = 1;
    // a[1] = 1;
    // rep(i, 2, N + 1)
    // {
    //     a[i] = i * a[i - 2];
    //     if (i == 5 || i == 10)
    //         ++ans;
    // }
    if (N % 2)
        ans = 0;
    else
    {
        ll p = 10, q = 50, r = 250, s, count1 = 1, count2 = 1;
        while (p <= N)
        {
            ans += N / p;
            p *= 10;
        }
        while (q <= N)
        {
            ans += (N / q + 1) / 2;
            q *= 10;
        }
        while (r <= N)
        {
            s = r;
            while (s <= N)
            {
                ans += (N / s + 1) / 2;
                s *= 5;
            }
            r *= 10;
        }
    }

    cout << ans << endl;
}
int main()
{
    func();
}