#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/dsu>
//using namespace atcoder;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 1001001001001001000;

int main() {
    int n; cin >> n;
    vector<pair<double, double>> p(n);
    rep(i,n) {
        double x,y; cin >> x >> y;
        p[i] = {x,y};
    }
    double ans = 0;

    rep(i,n) {
        rep(j,n) {
            double d = 0;
            d += (p[i].first-p[j].first)*(p[i].first-p[j].first);
            d += (p[i].second-p[j].second)*(p[i].second-p[j].second);
            ans += sqrt(d);
        }
    }
    ans = ans / n;
    printf("%.15f\n", ans);
    return 0;
}
