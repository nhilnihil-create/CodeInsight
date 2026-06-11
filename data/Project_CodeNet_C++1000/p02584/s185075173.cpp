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

    if (k <= abs(x) / d) {
        cout << abs(x) - k * d << endl;
        return 0;
    }

    k -= abs(x) / d;
    if (k % 2 == 0) {
        cout << abs(x) % d << endl;
    }
    else {
        cout << d - (abs(x) % d) << endl;
    }
    return 0;
}
