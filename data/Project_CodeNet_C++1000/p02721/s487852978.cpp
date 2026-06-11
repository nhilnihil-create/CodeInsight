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
    int n, k, c, d[200005] = {}, e[200005] = {};
    string s;
    vector<pii> a, b;
    cin >> n >> k >> c >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o' && i < c + 1) d[i] = 1;
        else if (s[i] == 'o' && i >= c + 1) d[i] = d[i - c - 1] + 1;
        else d[i] = d[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'o' && i + c + 1 >= n) e[i] = 1;
        else if (s[i] == 'o' && i + c + 1 < n) e[i] = e[i + c + 1] + 1;
        else e[i] = e[i + 1];
    }
    //for (int i = 0; i < n; i++) cout << d[i] << ' ' << e[i] << '\n';
    for (int i = 0; i < n; i++) if (s[i] == 'o' && d[i] + e[i] - 1 >= k) {
        int z = 0;
        if (i) z += d[i - 1];
        if (i + 1 < n) z += e[i + 1];
        if (z < k) cout << i + 1 << '\n';
    }
}
