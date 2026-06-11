#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    if (N == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 1; i <= N; ++i)
    {
        if (N <= (1 * pow(2, i) - 1))
        {
            cout << (ll)(1 * pow(2, i) - 1) << endl;
            return 0;
        }
    }
}
