#include <bits/stdc++.h>

#define debug(s) cout << s << endl
#define debug1(s, t) cout << s << " " << t << endl
#define debug2(s, t, u) cout << s << " " << t << " " << u << endl
#define printvec(v)       \
    for (auto &&i : v)    \
        cout << i << " "; \
    cout << endl
#define rep(n, i) for (int i = 0; i < n; i++)

using namespace std;
using i64 = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (auto &&pi : p)
    {
        cin >> pi;
    }

    sort(p.begin(), p.end());

    int price = 0;
    for (int i = 0; i < k; i++)
    {
        price += p[i];
    }

    cout << price << endl;

    return 0;
}