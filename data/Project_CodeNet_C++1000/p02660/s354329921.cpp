#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;
    int ans = 0;

    for (ll i = 2; i * i <= n; i++)
    {
        int cnt = 0;
        if (n % i)
        {
            continue;
        }
        while (n % i == 0)
        {
            n /= i;
            cnt++;
        }
        for (int j = 1; j <= cnt; j++)
        {
            cnt -= j;
            ans++;
        }
    }

    if (n > 1)
        ans++;

    cout << ans << endl;
}