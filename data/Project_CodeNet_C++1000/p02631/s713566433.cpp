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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &&ai : a)
    {
        cin >> ai;
    }

    // 解
    int overallsum = 0;
    for (int i = 0; i < n; i++)
    {
        overallsum ^= a[i];
    }
    vector<int> x(n, overallsum);
    for (int i = 0; i < n; i++)
    {
        x[i] ^= a[i];
    }
    
    printvec(x);

    return 0;
}