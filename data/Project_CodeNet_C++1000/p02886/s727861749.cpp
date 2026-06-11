#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;

    vector<int> d(n);
    rep (i, n)
        cin >> d[i];

    int ans = 0;
    rep (i, n)
        rep (j, n)
            if (i != j)
                ans += d[i] * d[j];

    cout << ans / 2 << endl;
    return 0;
}