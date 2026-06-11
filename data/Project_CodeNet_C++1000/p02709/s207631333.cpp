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
    int n;
    ll a[2020] = {}, d[2020][2020] = {}, z = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int b = 0;
        for (int j = 1; j <= n; j++) if (a[j] > a[b]) b = j;
        for (int j = 0; j <= i; j++) {
            if (!j) d[i][j] = d[i - 1][j] + a[b] * abs(b - (n - i + j + 1));
            else if (j == i) d[i][j] = d[i - 1][j - 1] + a[b] * abs(b - j);
            else d[i][j] = max(d[i - 1][j] + a[b] * abs(b - (n - i + j + 1)), d[i - 1][j - 1] + a[b] * abs(b - j));
        }
        a[b] = 0;
    }
    for (int i = 0; i <= n; i++) {
        z = max(z, d[n][i]);
        //for (int j = 0; j <= i; j++) cout << d[i][j] << " \n"[j == i];
    }
    cout << z;
}
