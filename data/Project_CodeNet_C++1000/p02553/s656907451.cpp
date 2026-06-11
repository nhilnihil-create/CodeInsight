#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define PI acos(-1)
#define fs first
#define sc second
#define MAX 0x3f3f3f3f
#define debug freopen("1.in", "r", stdin), freopen("1.out", "w", stdout);
#define ios                                                                    \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);                                                                \
    cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll maxn = 2e5 + 7;
ll a, b, c, d, ans;

int main() {
    cin >> a >> b >> c >> d;
    ans = max(a * c, a * d);
    ans = max(ans, b * c);
    ans = max(ans, b * d);
    cout << ans << '\n';

    return 0;
}