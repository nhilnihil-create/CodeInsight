#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

const ll mxN = 1e18;
ll n, ans = mxN;

int main()
{
    cin >> n;

    for (ll i = 1; i * i <= n; i++)
    {
        if (!(n % i))
        {
            ans = min(ans, i + n / i - 2);
        }
    }

    cout << ans << endl;
}