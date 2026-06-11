#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const int INF = 1000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

int main()
{
    ll n;
    cin >> n;

    if (n % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    ll den = 10;
    while (den <= n) {
        ans += n / den;
        den *= 5;
    }
    cout << ans << endl;
    return 0;
}