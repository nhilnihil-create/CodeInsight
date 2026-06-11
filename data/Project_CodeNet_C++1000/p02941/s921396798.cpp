#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define l first
#define r second
#define int long long

int n;
int a[500000];
int b[500000];

set<pair<int, int>, greater<pair<int, int> > > ss;

signed main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i], ss.insert({b[i], i});
    int ans = 0;
    for (;;)
    {
        if (ss.size() == 0)
        {
            break;
        }
        pair<int, int> p = *ss.begin();
        ss.erase(ss.begin());
        int s = b[(n + p.second + 1) % n] + b[(n + p.second - 1) % n];
        if (p.first == a[p.second])
        {
            continue;
        }
        if (p.first - s < a[p.second])
        {
            cout << -1;
            return 0;
        }
        else
        {
            int kek = 0;
            if (ss.size() == 0)
                kek = a[p.second];
            else
                kek = min(a[p.second], (*ss.begin()).first);
            ans += (p.first - kek) / s;
            int d = ((p.first - kek) / s) * s;
            b[p.second] -= d;
            p.first -= d;
            ss.insert(p);
        }
    }
    cout << ans;
}