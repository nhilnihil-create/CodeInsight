#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int INF = 1e9;
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    cout << n * (n - 1) / 2 << endl;
}
int main(void)
{
    solve();
}