#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int ans = 0;
    while (n / k > 0)
    {
        n /= k;
        ans++;
    }
    if (n != 0)
        ans++;

    cout << ans << endl;
    return 0;
}