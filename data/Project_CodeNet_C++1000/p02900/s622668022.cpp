#include <iostream>
#include <algorithm>
#include <vector>
// #include <numeric>
using namespace std;

#define ll long long

ll gcd(ll a, ll b)
{
	if (a == 0) return b;
	return (a? gcd(b % a, a):b);
}

int main()
{
    ll a, b, n;
    cin >> a >> b;
    n = gcd(a, b);

    ll ans = 1;
    for (ll i = 2; i * i < n; i++)
    {
        if (!(n % i))
        {
            ans++;
            while (!(n % i)) n /= i;
        }
    }

    if (n != 1) ans++;
    cout << ans << "\n";
}