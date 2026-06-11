#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, d;
    cin >> n >> d;
    vector<vector<double>> x(n, vector<double>(d));
    rep(i,n)rep(j,d) cin >> x[i][j];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            double dist = 0;
            rep(k,d) {
                dist += (x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
            }
            dist = sqrt(dist);
            int idist = (int)dist;
            if (dist == (double)idist) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}