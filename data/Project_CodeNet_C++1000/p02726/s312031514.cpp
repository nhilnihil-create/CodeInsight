#include <bits/stdc++.h>
using namespace std;
int calc(int p, int q, int x, int y) {
    int ret = min(abs(x-p) + abs(y-q) + 1, abs(x-q) + abs(y-p) + 1);
    ret = min(ret, abs(p-q));
    return ret;
}
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    x--, y--;
    vector<int> ans(n-1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = calc(i, j, x, y);
            ans[k-1]++;
        }
    }
    for (auto p: ans) cout << p << endl;
    return 0;
}