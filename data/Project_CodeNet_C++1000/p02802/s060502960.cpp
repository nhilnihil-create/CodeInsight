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
    int n, m, a[100005] = {}, b[100005] = {}, c, y = 0, z = 0;
    string s;
    cin >> n >> m;
    while (m--) {
        cin >> c >> s;
        if (s == "AC") {
            if (!a[c]) y++;
            a[c] = 1;
        } else {
            if (!a[c]) b[c]++;
        }
    }
    for (int i = 1; i <= n; i++) if (a[i]) z += b[i];
    cout << y << ' ' << z;
}
