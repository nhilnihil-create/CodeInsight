#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    char c;
    cin >> c;
    cout << (char)(c + 1);
    return 0;
    int n, m, z = 0;
    string s[22] = {};
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i], s[i] = '#' + s[i] + '#';
    for (int i = 0; i <= m + 1; i++) s[0] += '#', s[n + 1] += '#';
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (s[i][j] == '.') {
        for (int k = 1; k <= n; k++) for (int l = 1; l <= m; l++) if (s[k][l] == '.') {
            int d[22][22] = {};
            d[i][j] = 1;
            queue<pii> q;
            q.push({i, j});
            while (!q.empty()) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                if (s[x - 1][y] == '.' && !d[x - 1][y]) d[x - 1][y] = d[x][y] + 1, q.push({x - 1, y});
                if (s[x + 1][y] == '.' && !d[x + 1][y]) d[x + 1][y] = d[x][y] + 1, q.push({x + 1, y});
                if (s[x][y - 1] == '.' && !d[x][y - 1]) d[x][y - 1] = d[x][y] + 1, q.push({x, y - 1});
                if (s[x][y + 1] == '.' && !d[x][y + 1]) d[x][y + 1] = d[x][y] + 1, q.push({x, y + 1});
            }
            if (d[k][l]) z = max(z, d[k][l] - 1);
        }
    }
    cout << z;
}
