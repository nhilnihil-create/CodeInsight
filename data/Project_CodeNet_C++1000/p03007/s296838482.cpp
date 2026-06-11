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

    int n, a[112345];

    cin >> n;
    REP(i, n)
    cin >> a[i];

    sort(a, a + n);

    V p, m;

    ll res = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            res -= a[i];
            m.push_back(a[i]);
        }
        else
        {
            res += a[i];
            p.push_back(a[i]);
        }
    }

    if (p.size() == 0)
    {
        res += m[m.size() - 1] * 2;
        p.push_back(m[m.size() - 1]);
        m.pop_back();
    }

    if (m.size() == 0)
    {
        res -= p[0] * 2;
        m.push_back(p[0]);
        p.erase(p.begin());
    }

    cout << res << endl;

    while (true)
    {
        if (p.size() == 1)
        {
            cout << p[0] << " " << m[m.size() - 1] << endl;

            p[0] = p[0] - m[m.size() - 1];
            m.pop_back();
        }
        else
        {
            cout << m[0] << " " << p[p.size() - 1] << endl;

            m[0] = m[0] - p[p.size() - 1];
            p.pop_back();
        }

        if (p.size() + m.size() == 1)
            return 0;
    }

    return 0;
}