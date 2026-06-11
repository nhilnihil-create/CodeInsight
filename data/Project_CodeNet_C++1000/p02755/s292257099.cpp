#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    int a, b;
    cin >> a >> b;
    rep(i, 2000)
    {
        if (i * 8 / 100 == a && i * 10 / 100 == b)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}