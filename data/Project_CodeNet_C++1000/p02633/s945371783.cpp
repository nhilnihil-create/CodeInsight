#include <iostream>

using namespace std;

int main(void)
{
    int X;
    cin >> X;

    int a, b, r, x;
    a = 360;
    b = X;
    r = a % b;
    x = a * b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }

    int K;
    K = (x / b) / X;

    cout << K << "\n";
}
