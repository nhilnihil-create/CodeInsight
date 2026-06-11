#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int n;
    cin >> n;
    int a[n];
    rep (i, n) cin >> a[i];
    rep (i, n) {
        cout << "node " << i + 1 << ": key = " << a[i];
        if (i != 0) cout << ", parent key = " << a[(i - 1) / 2];
        if (i * 2 + 1 < n) {
            cout << ", left key = " << a[i * 2 + 1];
            if (i * 2 + 2 < n) cout << ", right key = " << a[i * 2 + 2];
        }
        cout << ", \n";
    }
}
