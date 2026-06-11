#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    ll s;
    cin >> s;
    ll x, y;
    x = (INF - s % INF)%INF;
    y = (s + x) / INF;

    cout << "0 0 " << INF << " 1 " << x << " " << y << endl;
    return 0;
}