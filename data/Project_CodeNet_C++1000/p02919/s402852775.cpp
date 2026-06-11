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

    multiset<int> s;

    ll res = 0;

    s.insert({-1, -1, q[n], n, n});

    for (int i = n - 1; i > 0; i--)
    {
        int pos = q[i];

        int l2 = *----s.lower_bound(pos);
        int l1 = *--s.lower_bound(pos);
        int r1 = *s.lower_bound(pos);
        int r2 = *++s.lower_bound(pos);

        res += (ll)(pos - l1) * (r2 - r1) * i;
        res += (ll)(r1 - pos) * (l1 - l2) * i;

        s.insert(pos);
    }

    cout << res << endl;

    return 0;
}