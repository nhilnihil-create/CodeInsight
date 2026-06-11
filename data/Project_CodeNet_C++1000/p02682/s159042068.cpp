//time:
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    if (a >= k)
    {
        cout << k << endl;
    }
    else if (a + b >= k)
    {
        cout << a << endl;
    }
    else
    {
        int ans = a;
        k -= (a + b);
        while (k > 0)
        {
            ans--;
            k--;
        }
        cout << ans << endl;
    }
    return 0;
}