#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MAX = 100 + 5;
const int INF = (int) 1e9;
int memo[MAX][MAX];
char grid[MAX][MAX];
int n, m;

int cost(int x, int y, int a, int b) {
    return grid[x][y] == '.' && grid[a][b] == '#';
}

int roll(int x, int y) {
    if (x == n && y == m) {
        return 0;
    }
    int &ans = memo[x][y];
    if (~ans) {
        return ans;
    }
    ans = INF;
    if (x + 1 <= n) {
        ans = min(ans, roll(x + 1, y) + cost(x, y, x + 1, y));
    }
    if (y + 1 <= m) {
        ans = min(ans, roll(x, y + 1) + cost(x, y, x, y + 1));
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    fori (i, 1, n + 1) {
        fori (j, 1, m + 1) {
            cin >> grid[i][j];
        }
    }
    memset(memo, -1, sizeof memo);
    cout << roll(1, 1) + (grid[1][1] == '#') << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

