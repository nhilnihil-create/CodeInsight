#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    string s, t;
    int a[200005][26] = {}, n, m;
    ll z = 0;
    cin >> s >> t;
    n = (int)s.length(), m = (int)t.length();
    s += s;
    for (int i = 0; i <= n + n; i++) for (int j = 0; j < 26; j++) a[i][j] = mod;
    for (int i = 0; i < n + n; i++) a[i][s[i] - 'a'] = 1;
    for (int i = n + n - 1; i >= 0; i--) for (int j = 0; j < 26; j++) a[i][j] = min(a[i][j], a[i + 1][j] + 1);
    //for (int i = 0; i <= n; i++) for (int j = 0; j < 3; j++) cout << a[i][j] << " \n"[j == 2];
    for (int i = 0; i < m; i++) {
        if (a[z % n][t[i] - 'a'] == mod) {
            cout << -1;
            return 0;
        }
        z += a[z % n][t[i] - 'a'];
    }
    cout << z;
}
