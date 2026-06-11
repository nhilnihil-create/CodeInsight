//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int tt;
    tt = 1;
    while (tt--)
    {
        int n, i, j, k, count = 0;
        cin >> n;
        int a[n + 1];
        for (i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (i = 1; i <= n; i++)
        {
            for (j = i + 1; j <= n; j++)
            {
                if (a[i] != a[j])
                {
                    for (k = j + 1; k <= n; k++)
                    {
                        if (a[k] != a[i] && a[k] != a[j])
                        {
                            if (a[i] + a[j] <= a[k] || a[i] + a[k] <= a[j] || a[j] + a[k] <= a[i])
                            {
                                continue;
                            }
                            else
                            {
                                count++;
                            }
                        }
                    }
                }
            }
        }
        cout << count << " " << endl;
    }
    return 0;
}