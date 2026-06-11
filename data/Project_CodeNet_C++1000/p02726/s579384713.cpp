#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;
#define ll long long
#define INF (int)(1e9+5)
#define MOD (int)(1e9 + 7) 
#define pi 3.14159265

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> ans(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            int res = INF;
            res = min(res, j - i);
            res = min(res, abs(x - i) + abs(y - j) + 1);
            ans[res]++;
        }
    }
    for(int i = 1; i < n; ++i) cout << ans[i] << '\n';
    return 0;
}

