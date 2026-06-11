#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int min = 0;
    if (d < b)
    {
        min += 60 - b + d;
        min += (c - a - 1) * 60;
    }
    else
    {
        min += d - b;
        min += (c - a) * 60;
    }
    int diff = min - e;

    if (diff <= 0)
        cout << 0 << endl;
    else
        cout << diff << endl;
}