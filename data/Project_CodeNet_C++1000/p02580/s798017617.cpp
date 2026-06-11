#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, m, k, x, y;
    pii a[300005] = {}, b[300005] = {};
    cin >> n >> m >> k;
    set<pii> s;
    while (k--) cin >> x >> y, a[x].first++, b[y].first++, s.insert({x, y});
    for (int i = 1; i <= n; i++) a[i].second = i;
    for (int i = 1; i <= m; i++) b[i].second = i;
    sort(a + 1, a + n + 1); sort(b + 1, b + m + 1);
    for (int i = n; i; i--) {
        for (int j = m; j; j--) {
            if (s.find({a[i].second, b[j].second}) == s.end()) {
                cout << a[n].first + b[m].first;
                return 0;
            }
            if (b[j].first != b[j - 1].first) break;
        }
        if (a[i].first != a[i - 1].first) break;
    }
    cout << a[n].first + b[m].first - 1;
}
