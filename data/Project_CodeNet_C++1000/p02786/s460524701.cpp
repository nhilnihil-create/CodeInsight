#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll h;
    cin >> h;
    int cnt = 0;
    while (h)
    {
        cnt++;
        h /= 2;
    }
    ll ans = (ll)pow(2, cnt) - 1;
    cout << ans << endl;
    return 0;
}