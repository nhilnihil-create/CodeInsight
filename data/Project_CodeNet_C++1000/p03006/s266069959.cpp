#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;
constexpr int di[] = {0, 0, 1, -1};
constexpr int dj[] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll x[51], y[51];

    cin >> n;
    REP(i, n)
    cin >> x[i] >> y[i];

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    int res = 1000;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll p = (x[i] - x[j]);
            ll q = (y[i] - y[j]);

            int r = n;

            for (int k = 0; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if ((p == (x[k] - x[l]) && q == (y[k] - y[l])) ||
                        (p == -(x[k] - x[l]) && q == -(y[k] - y[l])))
                        r--;
                }
            }

            res = min(res, r);
        }
    }

    cout << res << endl;

    return 0;
}