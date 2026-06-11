#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
const int MOD = 1000000007;
const int INF = 1e9 + 1;
using namespace std;
void solve(void)
{
    int h, w, n;
    cin >> h >> w >> n;
    int c_h = 0, c_w = 0;
    int x = 0;
    if (w > h)
        swap(h, w);
    while (x < n)
    {
        if (c_h < w)
            x += h - c_w, c_h++;
        else
            x += w - c_h, c_w++;
    }
    cout << c_h + c_w << endl;
}
int main(void)
{
    solve();
}