#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    if (n % 2) // odd
    {
        cout << 0 << endl;
    }
    else
    {
        long long div = 10, ans = 0;
        while (n / div > 0)
        {
            ans += n / div;
            div *= 5;
        }
        cout << ans << endl;
    }    
}