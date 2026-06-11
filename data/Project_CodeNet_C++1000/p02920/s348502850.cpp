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

    int n, s[(1 << 18) + 10];

    cin >> n;
    REP(i, 1 << n)
    cin >> s[i];

    sort(s, s + (1 << n));

    int i = (1 << n) - 1;

    priority_queue<int> q;

    q.push((1 << (n + 1)) - 1);

    while (i >= 0)
    {
        int cnt = 1;

        while (i >= 0 && s[i] == s[i - 1])
        {
            cnt++;
            i--;
        }

        if (cnt > q.size())
        {
            cout << "No" << endl;
            return 0;
        }

        V v;

        REP(j, cnt)
        {
            v.push_back(q.top());
            q.pop();
        }

        REP(j, cnt)
        {
            int p = v[j];

            int k = 2;
            while (true)
            {
                if (p / k < 1)
                    break;

                q.push(p / k);

                k *= 2;
            }
        }

        i--;
    }

    cout << "Yes" << endl;

    return 0;
}