#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a;
    a.push_back(2);
    rep(i, 0, 18) a.push_back(a[i] * 2);

    if (n < 3)
    {
        cout << "No" << endl;
        return 0;
    }
    for (auto x : a)
        if (x == n)
        {
            cout << "No" << endl;
            return 0;
        }

    cout << "Yes" << endl;
    if (n % 2 == 1)
    {
        for (int i = 2; i <= 2 * n; i += 2)
        {
            if (i - 1 == n)
                continue;
            cout << 1 << ' ' << i << endl;
        }
        for (int i = 2; i <= 2 * n; i += 2)
        {
            cout << i << ' ' << i + 1 << endl;
            if (i - 1 == n)
                i--;
        }
    }
    else
    {
        n--;

        for (int i = 2; i <= 2 * n + 2; i += 2)
        {
            if (i - 1 == n)
            {
                i += 3;
            }
            cout << 1 << ' ' << i << endl;
        }
        for (int i = 2; i < 2 * n + 2; i += 2)
        {
            if (i - 1 == n)
            {
                i++;
                cout << i << ' ' << i + 1 << endl;
                i--;
                continue;
            }
            cout << i << ' ' << i + 1 << endl;
        }

        n++;

        int m = 0;
        while (a[m + 1] < n)
            m++;

        cout << n << ' ' << a[m] << endl;
        cout << 2 * n << ' ' << 2 * n - a[m] + 1 << endl;
    }

    return 0;
}
