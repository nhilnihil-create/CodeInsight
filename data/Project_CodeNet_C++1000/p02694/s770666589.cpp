#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll X;
    cin >> X;
    ll m = 100;
    ll cnt = 0;
    while (m < X)
    {
        m += m / 100;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
