
#include <bits/stdc++.h>

using namespace std;

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
        }
        else
        {
            a -= d;
        }
        turn = !turn;
    }
    if (a > 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
