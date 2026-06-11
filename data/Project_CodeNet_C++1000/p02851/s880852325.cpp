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
    int n, k, a[200005] = {}, b[200005] = {};
    ll z = 0;
    map<int, int> m;
    m[0] = 1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i]--, a[i] %= k;
    for (int i = 1; i <= n; i++) {
        if (i >= k) m[b[i - k]]--;
        b[i] = (b[i - 1] + a[i]) % k, z += m[b[i]], m[b[i]]++;
    }
    cout << z;
}
