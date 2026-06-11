#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n; cin >> n;
    vector<long long> a(n);
    long long amax = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        amax = max(amax, a[i]);
    }
    sort(a.begin(), a.end());
    vector<bool> dp(amax, false);
    long long tar;
    for (int i = 0; i < n; i++)
    {
        tar = a[i] * 2;
        while (tar <= amax)
        {
            dp[tar - 1] = true;
            tar += a[i];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == a[i - 1] || a[i] == a[i + 1]) continue;
        else if (!dp[a[i] - 1])
        {
            ans++;
        }
    }
    cout << ans << endl;
}