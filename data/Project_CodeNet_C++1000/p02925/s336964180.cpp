#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, a[1003][1003] = {}, b[1003] = {}, z = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j < n; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++) b[i] = 1;
    queue<pair<pii, int>> q;
    for (int i = 1; i <= n; i++) if (a[a[i][1]][1] == i && i < a[i][1]) q.push({{i, a[i][1]}, 1});
    while (!q.empty()) {
        pii x = q.front().first;
        int y = q.front().second;
        z = max(z, y);
        //cout << x.first << ' ' << x.second << ' ' << y << '\n';
        q.pop();
        b[x.first]++;
        int w = a[x.first][b[x.first]];
        if (a[w][b[w]] == x.first) q.push({{x.first, w}, y + 1});
        b[x.second]++;
        w = a[x.second][b[x.second]];
        if (a[w][b[w]] == x.second) q.push({{x.second, w}, y + 1});
    }
    for (int i = 1; i <= n; i++) if (b[i] < n) z = -1;
    cout << z;
}
