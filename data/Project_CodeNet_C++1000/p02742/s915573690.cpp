#include <iostream>
using namespace std;

int main(void)
{
    long long h = 0;
    long long w = 0;
    cin >> h >> w;

    long long canmove = 0;
    if (h == 1 || w == 1)
    {
        canmove = 1;
    }
    else if (h % 2 == 0)
    {
        canmove = h / 2 * w;
    }
    else
    {
        if (w % 2 == 0)
        {
            canmove = h * w / 2;
        }
        else
        {
            canmove = (h - 1) / 2 * w + (w + 1) / 2;
        }
    }

    cout << canmove;

    return 0;
}