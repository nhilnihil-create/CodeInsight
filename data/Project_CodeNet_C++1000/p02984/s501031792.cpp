#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int n;
    cin >> n;
    ll a[n], offset = 0;
    rep (i, n) {
        cin >> a[i];
        a[i] *= 2;
    }
    rep (i, n) offset = a[i] - offset;
    offset /= 2;
    rep (i, n) {
        cout << offset << " ";
        offset = a[i] - offset;
    }
    cout << "\n";
}
