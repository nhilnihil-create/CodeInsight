#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
using namespace std;
using ll = unsigned long long;
using p = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    int count = 0;
    rep(i, 0, m)
    {
        int a;
        cin >> a;
        count += a;
    }

    int ans = n - count;
    if (ans >= 0)
    {
        cout << n - count << endl;
        return 0;
    }

    cout << "-1" << endl;

    return 0;
}
