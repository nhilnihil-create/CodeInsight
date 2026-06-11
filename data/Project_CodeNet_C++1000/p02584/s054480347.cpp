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
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const int INF = 1000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

int main()
{
    ll x, k, d;
    cin >> x >> k >> d;

    x = abs(x);
    if (k <= x / d) {
        cout << x - k * d << endl;
        return 0;
    }
    k -= x / d;
    x = x % d;
    if (k % 2 == 0) cout << x << endl;
    else cout << d - x << endl;
    return 0;
}
