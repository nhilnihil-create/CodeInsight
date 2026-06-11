#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n, m;
    cin >> n >> m;
    vector<P> sc(m);
    rep(i, m) cin >> sc[i].first >> sc[i].second;

    rep(i, 1000)
    {
        int keta = 1;
        int ni = i / 10;
        vector<int> d(1, i % 10);
        while (ni)
        {
            keta++;
            d.push_back(ni % 10);
            ni /= 10;
        }
        reverse(all(d));
        if (keta != n)
            continue;

        bool flag = true;

        rep(j, m)
        {
            if (d[sc[j].first - 1] != sc[j].second)
            {
                flag = false;
            }
        }

        if (flag)
        {
            cout << i << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    return (0);
}
