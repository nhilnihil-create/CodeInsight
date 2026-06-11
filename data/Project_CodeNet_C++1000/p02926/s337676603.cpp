#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<tuple<double, ll, ll>> en;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) continue;
        else en.emplace_back(atan2(y, x), x, y);
    }
    if (en.empty()) {
        cout << 0 << endl;
        return 0;
    }
    sort(en.begin(), en.end());
    N = (int)en.size();
    vector<ll> xsum(N+1, 0), ysum(N+1, 0);
    for (int i = 0; i < N; i++) {
        xsum[i+1] = xsum[i] + get<1>(en[i]);
        ysum[i+1] = ysum[i] + get<2>(en[i]);
    }
    double ans = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            double s, t, u, v;
            s = (xsum[j]-xsum[i]);
            t = (ysum[j]-ysum[i]);
            u = xsum[N]-s;
            v = ysum[N]-t;
            double cand = max(sqrt(s*s+t*t), sqrt(u*u+v*v));
            ans = max(ans, cand);
        }
    }
    printf("%.20lf\n", ans);
    return 0;
}
