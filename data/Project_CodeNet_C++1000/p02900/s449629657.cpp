#include <iostream>
#include <algorithm>
#include <vector>
// #include <numeric>
using namespace std;

#define ll long long

//use built in gcd function?
// int gcd(int a, int b)
// {
//     return (a? gcd(b % a, a):b);
// }
template<class T>
T gcd(T a, T b) {
	if (a == 0) return b;
	return gcd(b % a, a);
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