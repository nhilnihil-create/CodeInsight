#include <iostream>

using namespace std;

int main(void)
{
    int A, B, tmp;
    cin >> A >> B;
    if (A > B)
    {
        tmp = A - B;
    }
    else
    {
        tmp = B - A;
    }
    if (tmp % 2 == 0)
    {
        if (A > B)
        {
            cout << A - tmp / 2 << endl;
        }
        else
        {
            cout << B - tmp / 2 << endl;
        }
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}