#include <iostream>
using namespace std;

int main(void)
{
    int a, b, c, d; cin >> a >> b >> c >> d;
    bool res;
    while (1)
    {
        c -= b;
        if (c <= 0)
        {
            cout << "Yes" << endl;
            return 0;
        }
        a -= d;
        if (a <= 0)
        {
            cout << "No" << endl;
            return 0;
        }
    }
}