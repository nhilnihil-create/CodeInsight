#include <bits/stdc++.h>
typedef long long ll;

#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
#define INF 10e12
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;
int main(void)
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n - 1);
    rep(i, 0, n) cin >> a[i], a[i]--;
    rep(i, 0, n) cin >> b[i];
    rep(i, 0, n - 1) cin >> c[i];
    int ans = 0;
    rep(i, 0, n)
    {
        ans += b[a[i]];
        if (i > 0 && a[i - 1] + 1 == a[i])
            ans += c[a[i - 1]];
    }
    cout << ans << endl;
}