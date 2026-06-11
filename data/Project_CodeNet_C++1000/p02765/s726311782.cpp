#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    ll n, r;
    cin >> n >> r;
    if (n > 9)
    {
        cout << r << endl;
    }
    else
    {
        cout << r + 100 * (10 - n) << endl;
    }
    return 0;
}