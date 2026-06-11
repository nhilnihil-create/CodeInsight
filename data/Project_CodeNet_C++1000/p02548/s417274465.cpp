#include <iostream>
#include <math.h>
using namespace std;

int div(int n)
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else if (n == 3)
        return 2;
    else
    {
        int s = 0;
        int n2 = sqrt(n);
        for (int i = 1; i <= n2; i++)
        {
            if (n % i == 0)
                s++;
        }
        int n3 = sqrt(n);
        if (pow(n3, 2) == n)
            s = s * 2 - 1;
        else
            s *= 2;

        return s;
    }
}

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += div(i);
    }
    cout << ans << endl;
}