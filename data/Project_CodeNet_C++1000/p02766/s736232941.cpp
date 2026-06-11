#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;
    int w = n / k;
    int ans = 1;
    while (w != 0)
    {
        w = w / k;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
