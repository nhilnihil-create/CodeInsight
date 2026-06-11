#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, d;
    cin >> n >> d;
    vector<vector<double>> x(n, vector<double>(d));
    rep(i, n) rep(j, d) cin >> x[i][j];
    int ans = 0;
    rep(j, n) rep(i, j) {
        // distance
        double dist = 0;
        rep(k, d) {
            dist += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
        }
        dist = sqrt(dist);
        if (ceil(dist) == floor(dist)) ans++;
    }
    cout << ans << endl;
    return 0;
}