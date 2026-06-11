#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    vector<pair<double, double>> v;
    double x[n],y[n];
    rep(i,n){
        cin >> x[i] >> y[i];
        v.emplace_back(x[i], y[i]);
    }
    auto f = [](pair<double, double> p1, pair<double, double> p2){ return atan2(p1.second, p1.first) < atan2(p2.second, p2.first); };
    sort(ALL(v), f);
    double ans = 0;
    rep(i,n){
        double X = 0, Y = 0;
        rep(j,n){
            X += v[(i + j) % n].first;
            Y += v[(i + j) % n].second;
            ans = max(ans, sqrt(X * X + Y * Y));
        }
    }
    printf("%.12lf\n", ans);
    return 0;
}