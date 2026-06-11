#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int top(int n)
{
    return n / pow(10, to_string(n).length() - 1);
}

int bottom(int n)
{
    return n % 10;
}

int main()
{
    ll N;
    cin >> N;

    vector<vector<ll>> cnt(10, vector<ll>(10, 0));
    rep(i, N + 1) cnt[top(i)][bottom(i)]++;
    ll ans = 0;
    rep(x, 9) rep(y, 9)
    {
        ans += cnt[x + 1][y + 1] * cnt[y + 1][x + 1];
    }

    cout << ans << endl;

    return 0;
}
