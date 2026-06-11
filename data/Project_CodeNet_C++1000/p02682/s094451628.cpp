#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, k;
    cin >> a >> b >> c;
    cin >> k;
    int sum = 0;
    if (k <= a)
    {
        sum += k * 1;
    }
    else
    {
        sum += a * 1;
        k -= a;
        if (k <= b)
        {
            sum += k * 0;
        }
        else
        {
            sum += b * 0;
            k -= b;
            if (k <= c)
            {
                sum += k * (-1);
            }
            else
            {
                sum += c * (-1);
            }
        }
    }
    cout << sum;
}
