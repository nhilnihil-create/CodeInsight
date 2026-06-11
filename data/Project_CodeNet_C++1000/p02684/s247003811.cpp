#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, a[200005] = {}, b[69][200005] = {}, c = 1;
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], b[0][i] = a[i];
    for (int i = 1; i <= 66; i++) for (int j = 1; j <= n; j++) b[i][j] = b[i - 1][b[i - 1][j]];
    for (int i = 62; i >= 0; i--) {
        if (k & (1ll << i)) c = b[i][c];
    }
    cout << c;
}
