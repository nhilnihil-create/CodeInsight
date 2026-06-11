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
    int k, n, a[200005] = {}, z = 0;
    cin >> k >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) z = max(z, a[i + 1] - a[i]);
    cout << min(k - z, a[n] - a[1]);
}
