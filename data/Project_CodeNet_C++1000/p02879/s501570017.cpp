#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if (a > 9)
    {
        cout << "-1" << endl;
        return 0;
    }

    if (b > 9)
    {
        cout << "-1" << endl;
        return 0;
    }

    cout << a * b << endl;

    return 0;
}