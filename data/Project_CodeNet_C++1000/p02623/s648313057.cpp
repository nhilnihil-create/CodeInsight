#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>


using namespace std;
const int maxn = 105;
const int inf = 0x3f3f3f3f;
typedef long long ll;


int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    ll k;
    while (cin >> n >> m >> k) {
        vector<ll> a(n), b(m), sum_a, sum_b;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        int ans = 0;
        sum_a.push_back(0);
        sum_b.push_back(0);
        for (int i = 0; i < n; ++i) {
            if (sum_a[i] > k) break;
            sum_a.push_back(sum_a[i] + a[i]);
        }
        for (int i = 0; i < m; ++i) {
            if (sum_b[i] > k) break;
            sum_b.push_back(sum_b[i] + b[i]);
        }
        int j = (int) sum_b.size() - 1;
        for (int i = 0; i < sum_a.size(); ++i) {
            if (sum_a[i] > k) break;
            while (sum_b[j] + sum_a[i] > k) {
                --j;
            }
            ans = max(ans, i + j);
        }
        cout << ans << endl;
    }

    return 0;
}
