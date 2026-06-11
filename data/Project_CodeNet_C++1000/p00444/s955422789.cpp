#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cassert>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const int MOD = 1e9 + 7;
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n, n)
    {
        int v = 1000 - n;
        int coins[] = {500, 100, 50, 10, 5, 1};
        int pos = 0, ans = 0;
        while(v > 0)
        {
            while(v - coins[pos] < 0) pos++;
            v -= coins[pos];
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}


