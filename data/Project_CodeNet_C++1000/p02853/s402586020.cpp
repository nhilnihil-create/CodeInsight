#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int x, y;
    cin >> x >> y;
    int res = 0;

    switch (x)
    {
    case 1:
        res += 300000;
        break;
    case 2:
        res += 200000;
        break;
    case 3:
        res += 100000;
    default:
        break;
    }

    switch (y)
    {
    case 1:
        res += 300000;
        break;
    case 2:
        res += 200000;
        break;
    case 3:
        res += 100000;
    default:
        break;
    }

    if (x+y==2) res += 400000;
    cout << res << endl;
    return 0;
}