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

int bit[11234567], bit_n;

int bit_sum(int i)
{
    int s = 0;
    while (i > 0)
    {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void bit_add(int i, int x)
{
    while (i <= bit_n)
    {
        bit[i] += x;
        i += i & -i;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, p[112345], q[112345];

    cin >> n;
    REP(i, n)
    {
        cin >> p[i];
        q[p[i]] = i;
    }

    V v;

    ll res = 0;

    v.push_back(-1);
    v.push_back(q[n]);
    v.push_back(n);

    for (int i = n - 1; i > 0; i--)
    {
        int pos = q[i];

        int vPos = lower_bound(v.begin(), v.end(), pos) - v.begin();

        v.insert(v.begin() + vPos, pos);

        if (vPos + 2 < v.size())
        {
            int large = v[vPos + 1];

            int l = v[vPos - 1];

            int r = v[vPos + 2];

            res += (ll)(pos - l) * (r - large) * i;
        }

        if (vPos - 2 >= 0)
        {
            int large = v[vPos - 1];

            int l = v[vPos - 2];

            int r = v[vPos + 1];

            res += (ll)(r - pos) * (large - l) * i;
        }
    }

    cout << res << endl;

    return 0;
}