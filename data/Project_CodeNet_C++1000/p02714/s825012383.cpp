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
    int n, b = 0;
    ll z = 0;
    string s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) b += (s[i - 1] == 'B');
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (s[i - 1] == 'R' && s[j - 1] == 'G') {
        z += b;
        int d = abs(i - j);
        if (min(i, j) - d > 0 && s[min(i, j) - d - 1] == 'B') z--;
        if (max(i, j) + d <= n && s[max(i, j) + d - 1] == 'B') z--;
        if (i % 2 == j % 2 && s[(i + j) / 2 - 1] == 'B') z--;
    }
    cout << z;
}
