#include <iostream>

using namespace std;

int main()
{
    double d, t, s, x;
    cin >> d >> t >> s;
    x = d / s;
    if (x > t)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
    }
}