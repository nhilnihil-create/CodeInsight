#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main()
{
    int a, b;
    cin >> a >> b;

    if (a != 1 && b != 1)
    {
        cout << 1;
    }
    else if (a != 2 && b != 2)
    {
        cout << 2;
    }
    else
    {
        cout << 3;
    }

    cout << endl;
}