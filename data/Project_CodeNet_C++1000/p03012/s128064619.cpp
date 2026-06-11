#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> w(n);
    rep(i, n) cin >> w[i];

    int ans = INT32_MAX;
    for (int i = 1; i < n; ++i)
    {
        int s1 = 0, s2 = 0;
        for (int j = 0; j < n; ++j)
        {
            if (j <= i)
                s1 += w[j];
            else
                s2 += w[j];
        }
        ans = min(ans, abs(s1 - s2));
    }
    cout << ans << endl;
}