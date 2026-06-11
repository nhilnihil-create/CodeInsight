#include <iostream>
using namespace std;

int main(void)
{
    long long x; cin >> x;
    long long a = 100;
    long long y = 0;
    while (a < x)
    {
        a = a + a / 100;
        y++;
    }
    cout << y << endl;
}