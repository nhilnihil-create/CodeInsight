#include <iostream>
#define int long long int
using namespace std;
signed main()
{
    int a, b, k;
    cin >> a >> b >> k;
    if (k <= a)
        a -= k;
    else
    {
        b -= (k - a);
        a = 0;
    }
    if (b < 0)
        b = 0;
    cout << a << " " << b << endl;
    return 0;
}
