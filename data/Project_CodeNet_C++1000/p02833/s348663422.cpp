#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    uint64_t n;
    cin >> n;

    if (n % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    n /= 2;
    uint64_t ans = 0;
    while (n > 0)
    {
        ans += n / 5;

        n /= 5;
    }

    cout << ans << endl;
    return 0;
}