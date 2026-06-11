#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        if (i <= a)
        {
            ans++;
        }
        else if (i <= (a + b))
        {
            /*nothing*/
        }
        else
        {
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}
