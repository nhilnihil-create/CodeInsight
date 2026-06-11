#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) \
    for (int i = 0; i < (n); ++i)
int K;

int main()
{
    cin >> K;
    ll tmp = 7 % K;
    rep(i, K + 1)
    {
        if (tmp % K == 0)
        {
            cout << i + 1 << endl;
            return 0;
        }
        tmp = (tmp * 10 + 7) % K;
    }
    cout << -1 << endl;
}
