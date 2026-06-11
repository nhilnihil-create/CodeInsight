#include <iostream>
#include <map>
#include <string>
using namespace std;

uint64_t gcd(uint64_t a, uint64_t b)
{
    if (a % b == 0)
    {
        return (b);
    }
    else
    {
        return (gcd(b, a % b));
    }
}

uint64_t lcm(uint64_t a, uint64_t b)
{
    return a * b / gcd(a, b);
}

int main()
{
    uint64_t a, b;
    cin >> a >> b;

    // cout << gcd(a, b) << endl;
    cout << (uint64_t)lcm(a, b) << endl;
    return 0;
}