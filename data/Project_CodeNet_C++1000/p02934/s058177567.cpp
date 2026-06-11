#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    long double a, ans = 0;
    cin >> n;
    rep (i, n)
    {
        cin >> a;
        ans += (long double)1 / a;
    }

    ans = (long double)1 / ans;
    cout << ans << endl;
    return 0;
}