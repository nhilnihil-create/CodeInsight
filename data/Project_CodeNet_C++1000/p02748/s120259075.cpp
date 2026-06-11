#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int dxx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 }, dyy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {
    int A, B, m;
    cin >> A >> B >> m;
    int a[A], b[B], x[m], y[m], c[m];
    int ans = 0, sum = inf;
    rep (i, A) {
        cin >> a[i];
        sum = min (sum, a[i]);
    }
    ans += sum;
    sum = inf;
    rep (i, B) {
        cin >> b[i];
        sum = min (sum, b[i]);
    }
    ans += sum;
    sum = inf;
    rep (i, m) {
        cin >> x[i] >> y[i] >> c[i];
        sum = min (sum, a[x[i] - 1] + b[y[i] - 1] - c[i]);
    }
    ans = min (ans, sum);
    cout << ans << "\n";
}
