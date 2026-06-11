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

int n, m, q, a[55] = {}, b[55] = {}, c[55] = {}, d[55] = {}, z = 0;
vector<int> e = {1};

void sol() {
    if (e.size() == n + 1) {
        int y = 0;
        for (int i = 0; i < q; i++) if (e[b[i]] - e[a[i]] == c[i]) y += d[i];
        z = max(z, y);
        return;
    }
    for (int i = e.back(); i <= m; i++) {
        e.push_back(i);
        sol();
        e.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    sol();
    cout << z;
}
