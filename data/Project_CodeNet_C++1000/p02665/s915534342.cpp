#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n+1);
    for (int i = 0; i <= n; ++i) cin >> a[i];
    vector<long long> s(n + 1);
    s[n] = a[n];
    for (int i = n - 1; i >= 0; --i)
    {
        s[i] = s[i + 1] + a[i]; 
    }
    vector<long long> b(n+1);
    b[0] = 1 - a[0];
    b[n] = 0;
    if (b[0] < 0)
    {
        cout << -1 << endl;
        return 0;
    }
    if (n == 0 && a[0] == 1)
    {
        if (a[1] == 0)
        {
            cout << 1 << endl;
            return 0;
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 1; i < n; ++i)
    {
        b[i] = (std::min)(2 * b[i - 1] - a[i], s[i + 1]);
        if (b[i] < b[i - 1] - a[i])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    if (a[n] > 2 * b[n - 1] || a[n] < b[n - 1])
    {
        cout << -1 << endl;
        return 0;
    }
    long long ans = 0;
    for (int i = 0; i < n + 1; ++i)
    {
        ans += a[i] + b[i];
    }
    cout << ans << endl;
    return 0;
}
