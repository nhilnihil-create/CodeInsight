#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, a[2000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int pos = 0;
            for (int k = n - 1; k >= 1; k /= 2)
            {
                while ((pos + k) < n && a[pos + k] < a[i] + a[j]) 
                {
                    pos += k;
                    if (k == n - 1) break;
                }
            }
            // pos++;
            if (pos > j && pos < n && a[pos] < a[i] + a[j]) ans += pos - j;
            // cout << i << ' ' << j << ' ' << pos << ' ' << ans << "\n";
        }
    }
    cout << ans << "\n";
}