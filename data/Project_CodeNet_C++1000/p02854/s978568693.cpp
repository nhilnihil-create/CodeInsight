#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}
double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (size_t i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        if (i == 0)
        {
            a[i] = b;
        }
        else
        {
            a[i] = a[i - 1] + b;
        }
    }
    ll ans = INT64_MAX;
    for (size_t i = 0; i < n - 1; i++)
    {
        ll b = abs(a[n - 1] - a[i] * 2);
        ans = min(ans, b);

        /* code */
    }
    cout << ans << endl;
    return 0;
}