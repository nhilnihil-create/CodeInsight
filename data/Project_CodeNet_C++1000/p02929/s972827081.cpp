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
    string s;

    bool d[212345];

    cin >> n >> s;

    int cnt = 0;

    d[0] = false;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
            d[i] = !d[i - 1];
        else
            d[i] = d[i - 1];
        cnt += d[i];
    }

    if (cnt != n || s[0] == 'W' || s[s.size() - 1] == 'W')
    {
        cout << 0 << endl;
        return 0;
    }

    ll res = 1;

    int ln = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (d[i])
            (res *= ln) %= MOD, ln--;
        else
            ln++;
    }

    for (ll i = 1; i <= n; i++)
        (res *= i) %= MOD;

    cout << res << endl;

    return 0;
}