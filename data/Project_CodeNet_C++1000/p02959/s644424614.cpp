#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long n;
    cin >> n;
    vector<long> a(n + 1);
    for (long i = 0; i < n + 1; i++)
    {
        cin >> a[i];
    }
    vector<long> b(n);
    for (long i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    long ans = 0;
    for (long i = 0; i < n; i++)
    {
        if (a[i] >= b[i])
        {
            ans += b[i];
        }
        else
        {
            ans += a[i];
            long dif = b[i] - a[i];
            if (dif >= a[i + 1])
            {
                ans += a[i + 1];
                a[i + 1] = 0;
            }
            else
            {
                ans += dif;
                a[i + 1] -= dif;
            }
        }
    }

    cout << ans << endl;
}