#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, d;
    cin >> n >> d;
    int x[n][d];
    rep(i,n)rep(j,d) cin >> x[i][j];
    int ans = 0;
    rep(i,n-1) for (int j = i+1; j < n; j++) {
        int s = 0;
        rep(k,d) s += pow(x[i][k]-x[j][k], 2);
        double r = pow(s, 1/2.);
        if (int(r)-r == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}
