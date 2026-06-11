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
    int n, p, c = 0, q[200005] = {1};
    ll a[10004] = {1}, z = 0;
    string s;
    cin >> n >> p >> s;
    if (p == 2 || p == 5) {
        for (int i = 1; i <= n; i++) if ((s[i - 1] - '0') % p == 0) z += i;
        cout << z;
        return 0;
    }
    for (int i = 1; i <= n; i++) q[i] = q[i - 1] * 10 % p;
    for (int i = 1; i <= n; i++) c = (c * 10 + s[i - 1] - '0') % p, a[(c * q[n - i]) % p]++;
    for (int i = 0; i < p; i++) z += a[i] * (a[i] - 1) / 2;
    cout << z;
}
