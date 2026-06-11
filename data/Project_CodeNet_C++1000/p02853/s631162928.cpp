#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int ret(int X)
{
    switch (X)
    {
    case 1:
        return 300000;
    case 2:
        return 200000;
    case 3:
        return 100000;

    default:
        return 0;
    }
}

int main()
{
    int X, Y;
    cin >> X >> Y;
    if (X == 1 && Y == 1)
    {
        cout << ret(X) + ret(Y) + 400000 << endl;
    }
    else
    {
        cout << ret(X) + ret(Y) << endl;
    }
}
