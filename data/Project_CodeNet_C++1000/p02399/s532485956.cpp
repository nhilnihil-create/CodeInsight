#include <iostream>
#include <iomanip>
using namespace std;

const int MIN = 1;
const int MAX = 1000000000;

bool isRange(int v)
{
    if ((MIN <= v) && (v <= MAX))
    {
        return true;
    }
    return false;
}

int main()
{
    int a, b;
    int d, r;
    double f;
    while (cin >> a >> b)
    {
        d = a / b;
        r = a % b;
        f = (double)a / (double)b;
        cout << d << " "<< r << " "<< fixed << std::setprecision(5) << f <<endl;
    }

    return (0);
}