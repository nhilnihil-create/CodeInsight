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
    int n, m, u, v, z[3] = {-1, -1, -1};
    cin >> n >> m;
    while (m--) {
        cin >> u >> v;
        u--;
        if (z[u] == -1) z[u] = v;
        else if (z[u] != v) {
            cout << -1;
            return 0;
        }
    }
    if (n > 1 && z[0] == 0) {
        cout << -1;
        return 0;
    }
    if (n > 1 && z[0] == -1) z[0] = 1;
    for (int i = 0; i < n; i++) {
        if (z[i] == -1) cout << 0;
        else cout << z[i];
    }
}
