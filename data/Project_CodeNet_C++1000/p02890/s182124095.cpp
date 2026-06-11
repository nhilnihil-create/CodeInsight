#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define chmin(x, y) x = min(x, y)

using namespace std;

typedef long long ll;

const int INF = 1001001001;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n)
    {
        int x;
        cin >> x;
        a[x - 1]++;
    }

    sort(a.begin(), a.end());
    vector<int> s(n + 1);
    REP(i, n)
    s[i + 1] = s[i] + a[i];

    for (int k = 1; k <= n; ++k)
    {
        int l = 0;
        int r = n / k + 1;
        while (l + 1 < r)
        {
            int c = (l + r) / 2;
            bool ok = [&](int c) {
                int i = lower_bound(a.begin(), a.end(), c) - a.begin();
                int sum = c * (n - i) + s[i];
                return (sum >= c * k);
            }(c);
            if (ok)
                l = c;
            else
                r = c;
        }
        printf("%d\n", l);
    }

    return 0;
}