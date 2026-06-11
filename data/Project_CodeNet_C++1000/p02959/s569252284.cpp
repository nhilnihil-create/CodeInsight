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

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n);
    for (size_t i = 0; i < n + 1; i++)
    {
        cin >> a[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    ll ans = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] < b[i])
        {
            ans += a[i];
            if (a[i + 1] < b[i] - a[i])
            {
                ans += a[i + 1];
                a[i + 1] = 0;
            }
            else
            {
                ans += b[i] - a[i];
                a[i + 1] -= b[i] - a[i];
            }
        }
        else
        {
            ans += b[i];
        }
    }
    cout << ans << endl;

    return 0;
}