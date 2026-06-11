#include <bits/stdc++.h>

using namespace std;

long long a[10000004];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            a[j] += j;
        }
        ans += a[i];
    }
    cout << ans << endl;
}
