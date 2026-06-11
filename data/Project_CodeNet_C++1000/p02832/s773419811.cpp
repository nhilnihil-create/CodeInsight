#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
const ll MOD = 1000000007;
using namespace std;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
int main(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, 0, n) cin >> v[i];
    int ans = n, cta = 1;
    rep(i, 0, n) if (v[i] == cta) cta++;
    if (n == n - cta + 1)
        cout << -1 << endl;
    else
        cout << n - cta + 1 << endl;
}