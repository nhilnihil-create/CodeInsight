#include <iostream>
using namespace std;
int main()
{
    int L, R, d;
    cin >> L >> R >> d;
    if (L % d == 0)
    {
        cout << R / d - L / d + 1 << endl;
    }
    else
    {
        cout << R / d - L / d << endl;
    }
    return 0;
}