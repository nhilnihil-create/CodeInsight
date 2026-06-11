#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b;
    cin >> a >> b;
    rep(yen, 1001)
    {
        int e = yen * 0.08;
        int t = yen * 0.1;
        if (e == a && t == b)
        {
            cout << yen << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}