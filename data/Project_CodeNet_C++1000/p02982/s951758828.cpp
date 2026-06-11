#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, d;
    cin >> n >> d;
    vector<vector<int>> x(n, vector<int>(d));
    rep(i, n)rep(j, d) cin >> x[i][j];
    vector<int> check(200);
    for (int i = 1; i <= 200; i++) check[i] = i * i;
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<int> y = x[i];
            vector<int> z = x[j];
            int dis = 0;
            rep(i, d) {
                int k = abs(y[i] - z[i]);
                dis += k * k;
            }
            bool ok = false;
            for (int i = 1; i <= 200; i++) {
                if (check[i] == dis) ok = true;
            }
            if (ok) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}