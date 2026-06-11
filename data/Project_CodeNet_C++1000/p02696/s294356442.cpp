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
const ll INF = 10000000000;
const double PI = acos(-1);
const ll mod = 998244353;

int main()
{
    ll a, b, n;
    cin >> a >> b >> n;

    ll c = 0;
    if (n < b) c = n;
    else c = b - 1;

    ll ans = (a * c) / b;
    cout << ans << endl;
    return 0;
}
