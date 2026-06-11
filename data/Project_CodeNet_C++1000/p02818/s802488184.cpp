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
const ll INF = 1000000000000000000;
const double PI = acos(-1);

int main()
{
    ll a, b, k;
    cin >> a >> b >> k;

    if (k < a) {
        a -= k;
    }
    else if (k < (a + b)) {
        b -= (k - a);
        a = 0;
    }
    else {
        a = 0;
        b = 0;
    }
    cout << a << ' ' << b << endl;
    return 0;
}