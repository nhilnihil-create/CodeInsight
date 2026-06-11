#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <iomanip>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    rep(i,n) cin >> p[i].first >> p[i].second;
    double ans = 0;
    rep(i,n) {
        rep(j,n) {
            if(i == j) continue;
            double dx, dy;
            dx = p[i].first - p[j].first;
            dy = p[i].second - p[j].second;
            ans += sqrt(dx*dx + dy*dy);
        }
    }
    ans /= n;
    cout << fixed << setprecision(10);
    cout << ans << endl;

    return 0;
}
