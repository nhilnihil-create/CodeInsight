#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i, n) for (int i = 0; i < (n); i++)
using pint = pair<int, int>;
using Graph = vector<vector<int>>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int n;
    cin >> n;
    ll x[n], l[n];
    pair<ll, ll> p[n];
    rep (i, n) {
        cin >> x[i] >> l[i];
        p[i].first = x[i] + l[i];
        p[i].second = x[i] + -l[i];
    }
    sort (p, p + n);
    ll now = p[0].first;
    int ans = n;
    for (int i = 1; i < n; i++) {
        if (now <= p[i].second) {
            now = p[i].first;
        } else {
            ans--;
        }
    }
    cout << ans << "\n";
}
