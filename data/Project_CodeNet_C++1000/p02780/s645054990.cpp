#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    ll a[200005] = {}, z = 0, b[200005] = {};
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = b[i - 1] + a[i] + 1;
    for (int i = k; i <= n; i++) z = max(z, b[i] - b[i - k]);
    cout << setprecision(13) << 1.0 * z / 2 << '\n';
}
