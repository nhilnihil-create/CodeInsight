#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bool turn = true;
    while (a > 0 && c > 0)
    {
        if (turn)
        {
            c -= b;
            turn = false;
        }
        else
        {
            a -= d;
            turn = true;
        }
    }

    if (a > 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}