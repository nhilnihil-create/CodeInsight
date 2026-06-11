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
    int n, x, y, z[2020] = {}, a[2020] = {}, b[2020] = {};
    cin >> n >> x >> y;
    for (int i = 1; i < x; i++) a[i] = x - i, b[i] = y - i;
    for (int i = y + 1; i <= n; i++) a[i] = i - x, b[i] = i - y;
    for (int i = x; i <= y; i++) a[i] = min(i - x, x + y + 1 - i + x), b[i] = min(y - i, x + y + 1 - y + i);
    for (int i = 1; i <= n; i++) for (int j = 1; j < i; j++) {
        z[min({i - j, a[i] + a[j], b[i] + b[j], a[i] + b[j] + 1, b[i] + a[j] + 1})]++;
    }
    for (int i = 1; i < n; i++) cout << z[i] << '\n';
}
