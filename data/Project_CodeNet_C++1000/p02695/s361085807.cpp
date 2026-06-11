#include <bits/stdc++.h>

const int INF = 1e9;
const int MOD = 1e9 + 7;

using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define FORD(i, a, b) for (int i = b - 1; i >= int(a); i--)
#define WRAP(y, x, h, w) (0 <= y && y < h && 0 <= x && x < w)

#define ALL(x) (x).begin(), (x).end()

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct str {
    int a, b, c, d;
};
int n, m, q;
vector<str> vstr;
vector<int> nums;
int ans = 0;
void dfs(int idx, int n, int num, int m)
{
    if (idx == n) {
        int a = 0;
        REP(i, q)
        {
            if (nums[vstr[i].b] - nums[vstr[i].a] == vstr[i].c)
                a += vstr[i].d;
        }
        ans = max(ans, a);
        return;
    }
    for (int i = num; i <= m; i++) {
        nums[idx]=i;
        dfs(idx + 1, n, i, m);
    }
}

int main()
{
    cin >> n >> m >> q;
    vstr.resize(q);
    REP(i, q)
    {
        cin >> vstr[i].a >> vstr[i].b >> vstr[i].c >> vstr[i].d;
        vstr[i].a--;
        vstr[i].b--;
    }
    nums.resize(n);
    dfs(0, n, 1, m);
    cout << ans << endl;
}