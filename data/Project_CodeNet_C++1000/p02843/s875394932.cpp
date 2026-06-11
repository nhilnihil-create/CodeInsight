#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
typedef long long ll;

int main()
{
    ll X;
    cin >> X;

    for (ll i = 0; i < X; ++i)
    {
        if (100 * i <= X && X <= 105 * i)
        {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;
}
