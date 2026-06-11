#include <iostream>
#include <iomanip>

typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for(ll i=init;i<(n);i++)

int main() {
    ll h, w;
    cin >> h >> w;
    if (w != 1 && h != 1)
        cout << ((h + 1) / 2) * ((w + 1) / 2) + (h / 2) * (w / 2) << endl;
    else
        cout << 1 << endl;
    return 0;
}