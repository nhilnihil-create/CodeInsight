#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int64_t x, k, d, tmp, ans;
    cin >> x >> k >> d;
    x = abs(x);
    tmp = x / d;

    if(x/d < k)
    {
        ans = x - (x/d)*d;

        if((k-(x/d)) % 2 != 0)
        {
            ans -= d;
        }

    }
    else
    {
        ans = x - k * d;
    }

    cout << abs(ans) << endl;
}