#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    if (n >= 2)
    {
        ans += (n * (n - 1)) / 2;
    }
    if (m >= 2)
    {
        ans += (m * (m - 1)) / 2;
    }
    cout << ans << endl;
    return 0;
}
