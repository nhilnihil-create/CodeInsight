#include <iostream>
using namespace std;
int n, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n / 2; i++)
    {
        ans += 1;
        if (i == n - i)
        {
            ans -= 1;
        }
    }
    cout << ans << endl;
    return 0;
}