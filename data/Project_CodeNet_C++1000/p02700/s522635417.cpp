#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    int a, b, c, d;
    int t_win, a_win;
    cin >> a >> b >> c >> d;
    t_win = 0;
    a_win = 0;
    for (;;)
    {
        c = c - b;
        if (c <= 0)
        {
            t_win = 1;
            break;
        }
        a = a - d;
        if (a <= 0)
        {
            a_win = 1;
            break;
        }
    }
    if (t_win == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
