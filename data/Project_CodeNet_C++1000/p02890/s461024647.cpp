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
    int n, a, b[300005] = {}, c[300005] = {}, d[300005] = {};
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a, c[a]++;
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++) d[c[i]]++;
    for (int i = 1; i <= n; i++) d[i] += d[i - 1];
    for (int i = 1; i <= n; i++) c[i] += c[i - 1];
    for (int i = 1; i <= n; i++) b[i] = c[d[i]] + (n - d[i]) * i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; ; j++) {
            if (b[j] < i * j) {
                cout << j - 1 << '\n';
                break;
            }
        }
    }
}
