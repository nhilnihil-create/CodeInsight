#include <iostream>
using namespace std;
long long gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int main()
{
    long long a, b, total = 0, c, d;
    cin >> a >> b >> c >> d;
    total += b / c - (a - 1) / c;
    total += b / d - (a - 1) / d;
    long long x = gcd(c, d);
    total -= b / (c * d / x) - (a - 1) / (c * d / x);
    total = b - a + 1 - total;
    cout << total << endl;
    return 0;
}
