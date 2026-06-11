#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n, x, y; cin >> n >> x >> y;
    x--;
    y--;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int tmp = min({ abs(i - j),abs(i - x) + 1 + abs(y - j),abs(i - y) + 1 + abs(x - j) });
            ans[tmp]++;
        }
    }
    for (int i = 1; i < n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}