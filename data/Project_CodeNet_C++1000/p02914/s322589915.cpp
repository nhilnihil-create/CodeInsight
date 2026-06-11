#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll p[64];

void ins(ll x)
{
    for (int i = 60; i >= 0; --i)
    {
        if (x >> i)
        {
            if (!p[i])
            {
                p[i] = x;
                break;
            }
            x ^= p[i];
        }
    }
}
ll num[100010];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    ll x, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> num[i];
        sum ^= num[i];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 60; j >= 0; --j)
        {
            if (((sum >> j) & 1) == 1 && ((num[i] >> j) & 1) == 1)
            {
                num[i] -= 1ll << j;
            }
        }
        ins(num[i]);
    }
    x = 0;
    for (int i = 60; i >= 0; --i)
    {
        x = max(x, x ^ p[i]);
    }
    cout << x + (x^sum);
}
