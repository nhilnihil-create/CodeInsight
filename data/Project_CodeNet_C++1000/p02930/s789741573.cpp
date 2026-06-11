#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

vector<vector<int>> level;

void dfs(int offset, int n, int L)
{
    if (n == 1) {
        return;
    }

    int m = n / 2;
    for (int i = offset; i < offset + m; i++) {
        for (int j = offset + m; j < offset + n; j++) {
            level[i][j] = level[j][i] = L;
        }
    }

    dfs(offset, m, L + 1);
    dfs(offset + m, n - m, L + 1);
}

int main()
{
    int n;
    cin >> n;

    level.resize(n, vector<int>(n));
    dfs(0, n, 1);
    rep(i, n - 1)
    {
        for (int j = i + 1; j < n; j++) {
            cout << level[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}