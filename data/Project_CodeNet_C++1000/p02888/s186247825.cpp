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
    int n, a[2020] = {}, c[2020] = {}, z = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], c[a[i]]++;
    for (int i = 1; i <= 2000; i++) c[i] += c[i - 1];
    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) {
        z += c[2000] - c[a[i] + a[j] - 1];
    }
    cout << 1ll * n * (n - 1) * (n - 2) / 6 - z;
}
