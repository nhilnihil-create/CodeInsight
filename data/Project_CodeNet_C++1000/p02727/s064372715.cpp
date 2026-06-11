#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
ll func2(ll *p, ll *q, ll *r, int A, int B, int C, int X, int Y)
{
    ll ans(0);
    ll max;
    int i(0);
    int x = X, y = Y, a = A, b = B, c = C;
    while (i++ < X + Y)
    {
        if (x && y)
        {
            max = p[a] > q[b] ? p[a] : q[b];
            max = max > r[c] ? max : r[c];
        }
        else if (x == 0 && y == 0)
            max = r[c];
        else if (x == 0)
            max = q[b] > r[c] ? q[b] : r[c];
        else if (y == 0)
            max = p[a] > r[c] ? p[a] : r[c];
        // cout << max << endl;
        ans += max;
        if (max)
        {
            if (max == p[a])
                --a, --x;
            else if (max == q[b])
                --b, --y;
            else if (max == r[c])
                --c;
        }
    }
    return ans;
}
void func()
{
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    ll p[A + 1], q[B + 1], r[C + 1];
    p[0] = 0;
    q[0] = 0;
    r[0] = 0;
    rep(i, 0, A) cin >> p[i + 1];
    rep(i, 0, B) cin >> q[i + 1];
    rep(i, 0, C) cin >> r[i + 1];
    sort(&p[0], &p[A + 1]);
    sort(&q[0], &q[B + 1]);
    sort(&r[0], &r[C + 1]);
    // rep(i, 0, A + 1) cout << p[i] << ' ';
    // cout << endl;
    // rep(i, 0, B + 1) cout << q[i] << ' ';
    // cout << endl;
    // rep(i, 0, C + 1) cout << r[i] << ' ';
    // cout << endl;
    ll ans = func2(p, q, r, A, B, C, X, Y);
    cout << ans << endl;
}
int main()
{
    func();
}