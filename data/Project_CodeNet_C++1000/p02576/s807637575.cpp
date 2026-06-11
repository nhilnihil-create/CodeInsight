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
const ll mod = 1000000007;

int main()
{
    int n, x, t;
    cin >> n >> x >> t;

    int ans = 0;
    while (n > 0) {
        n -= x;
        ans += t;
    }
    cout << ans << endl;
    return 0;
}
