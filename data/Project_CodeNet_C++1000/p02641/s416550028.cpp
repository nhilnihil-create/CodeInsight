#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

int main()
{
#ifdef WIN32
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x, n, t;
    cin >> x >> n;
    if (n == 0)
        cout << x << "\n";
    else
    {
        int arr[101];
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++)
        {
            cin >> t;
            arr[t]++;
        }
        int a = 101, b = 0;
        for (int i = x; i < 101; i++)
        {
            if (arr[i] == 0)
            {
                a = i;
                break;
            }
        }
        for (int i = x; i >= 0; i--)
        {
            if (arr[i] == 0)
            {
                b = i;
                break;
            }
        }
        if (x - b <= a - x)
            cout << b << "\n";
        else
            cout << a << "\n";
    }

    return 0;
}