#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (ll)n; ++i)
#define INF 10e7
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;

void solve(void)
{
    int n;
    cin >> n;
    int ans = -1;
    rep(i, n + 1)
    {
        if (floor(1.08 * i) == n)
            ans = i;
    }
    if (ans == -1)
        cout << ":(" << endl;
    else
        cout << ans << endl;
}

int main(void)
{
    solve();
}
