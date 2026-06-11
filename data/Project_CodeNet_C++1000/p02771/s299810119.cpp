#include <iostream>
using namespace std;

int main(void)
{
    int a = 0, b = 0, c = 0;

    cin >> a >> b >> c;

    if (a == b && c != a)
    {
        cout << "Yes";
    }
    else if (b == c && a != b)
    {
        cout << "Yes";
    }
    else if (c == a && b != c)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}