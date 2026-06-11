#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cctype>
#include <map>
#include <set>

const int INT_INF = 1e9;
const long long LONG_INF = 1e18;
const long long MOD = 1e9 + 7;
const double PI = 3.14159265358979323846;

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> c[i];
    }

    int ans = 0;
    ans += b[a[1]];
    for (int i = 2; i < n + 1; i++)
    {
        ans += b[a[i]];
        if (a[i] == a[i - 1] + 1)
        {
            ans += c[a[i - 1]];
        }
    }
    cout << ans << endl;
    return 0;
}