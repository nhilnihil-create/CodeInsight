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
    ll a[328] = {}, d[328][328] = {}, z = 328ll * mod;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) d[i][j] = 328ll * mod;
    d[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            for (int l = i - 1; l >= 0 && j - i + l + 1 >= 0; l--) {
                d[i][j] = min(d[i][j], d[l][j - i + l + 1] + max(0ll, a[i] - a[l]));
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        //for (int j = 0; j <= i; j++) cout << d[i][j] << ' '; cout << '\n';
    }
    for (int i = 0; i <= n; i++) if (k - n + i >= 0) z = min(z, d[i][k - n + i]);
    cout << z;
}
