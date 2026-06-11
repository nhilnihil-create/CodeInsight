#include <iostream>
using namespace std;
int main()
{
    int n, m, k, ans = 0, maxi = -1;
    bool out = false;
    cin >> n >> m >> k;
    int a[n + 1], b[m + 1];
    a[0] = 0;
    b[0] = 0;
    long long total = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(total + a[i] <= k && !out)
        {
            total += a[i];
            maxi = i;
        }
        else
        {
            out = true;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    for(int i = maxi, j = 0; i >= 0; i--)
    {
        while(j < m && total + b[j + 1] <= k)
        {
            total += b[++j];
        }
        ans = max(ans, i + j);
        total -= a[i];
    }
    cout << ans << endl;
    return 0;
}
