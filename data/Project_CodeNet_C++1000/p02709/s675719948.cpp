#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> Pair;
const int maxn = 2000 + 7;

int n;
vector<Pair> o;
long long f[maxn][maxn];

long long dp(int x, int y) {
    if (x > y) return 0;
    if (f[x][y] != -1) return f[x][y];

    int u = y - x;
    f[x][y] = max(o[u].first * abs(o[u].second - x) + dp(x + 1, y), 
                  o[u].first * abs(o[u].second - y) + dp(x, y - 1));
    return f[x][y];
}

int main() {
    scanf("%d", &n);
    for (int i = 1, v; i <= n; i++) {
        scanf("%d", &v);    
        o.push_back({v, i});
    }

    sort(o.begin(), o.end());
    memset(f, -1, sizeof(f));

    cout << dp(1, n) << endl;
    return 0;
}
