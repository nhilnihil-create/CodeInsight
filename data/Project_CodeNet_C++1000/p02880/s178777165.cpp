#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    rep(j, 2) for (int i = 9; i > 1; i--)
    {
        if (n % i == 0)
        {
            n /= i;
            break;
        }
    }

    if (n == 1)
        cout << "Yes" << endl;
    else
    {
        cout << "No" << endl;
    }
    return 0;
}