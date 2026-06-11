#include <bits/stdc++.h>
using namespace std;

#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false

int main()
{
    int n;
    int i, j, k;
    int ans = 0;
    while (cin >> n)
    {
        ans = 0;
        i = 0;
        j = 0;
        k = 0;
        rep(i, 10)
        {
            rep(j, 10)
            {
                rep(k, 10)
                {
                    if (0 <= n - i - j - k && n - i - j - k <= 9)
                    {
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}