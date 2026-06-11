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

#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(e, i) for (auto e: i)
#define all(x) x.begin(), x.end()


using namespace std;
const int maxn = 105;
const int inf = 0x3f3f3f3f;
typedef long long ll;


// DFS Ver
int main() {
#ifdef AZUKI_LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s1, s2;
    while (cin >> s1 >> s2) {
        int ans = 0;
        rep(i, s1.size()) {
            ans += (s1[i] != s2[i]);
        }
        cout << ans << endl;
    }

    return 0;
}
