#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
typedef long long ll;

int main()
{
    int X;
    cin >> X;
    int k = 1;

    while (true)
    {
        int tar = k * X;
        if (tar % 360 == 0)
        {
            cout << k << endl;
            return 0;
        }
        ++k;
    }
}
