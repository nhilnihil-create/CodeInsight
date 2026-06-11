#include <algorithm>
#include <iostream>
using namespace std;

int main(void)
{
    long long a, b, c, d;
    long long ans;
    cin >> a >> b >> c >> d;

    if (b > 0 && d > 0)
    {
        ans = max(b * d, a * c);
    }
    else if (b <= 0 && d <= 0)
    {
        ans = a * c;
    }
    else if (b > 0 && d <= 0)
    {
        if (a >= 0)
            ans = a * d;
        else
            ans = a * c;
    }
    else if (b <= 0 && d > 0)
    {
        if (c >= 0)
            ans = c * b;
        else
            ans = c * a;
    }

    cout << ans << endl;
    return 0;
}