#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a == 1)
    {
        if (b == 2)
            cout << 3 << endl;
        else
            cout << 2 << endl;
    }
    else if (a == 2)
    {
        if (b == 1)
            cout << 3 << endl;
        else
            cout << 1 << endl;
    }
    else
    {
        if (b == 1)
            cout << 2 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}
