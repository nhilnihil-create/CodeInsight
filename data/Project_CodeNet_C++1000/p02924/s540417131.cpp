#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    n--;
    ll ans = (ll)(n + 1) * n / 2;
    cout << ans << endl;
    return 0;
}