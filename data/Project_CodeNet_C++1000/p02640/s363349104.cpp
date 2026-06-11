#include <iostream>
using namespace std;

int main(void)
{
    int x, y, a, b;
    cin >> x >> y;
    a = (4 * x - y) / 2;
    b = (y - 2 * x) / 2;

    if (y % 2 == 0 && 4 * x - y >= 0 && y - 2 * x >= 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}