#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T, class U> inline bool chmax(T& a,U b) { if (a < b) { a = b; return 1; } return 0; }
using point = pair<long double, long double>;

int main() {
    int n;
    cin >> n;
    vector<point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].second >> p[i].first;
    }
    
    sort(p.begin(), p.end(), [](const point &l, const point &r) {
        return atan2l(l.first, l.second) < atan2l(r.first, r.second);
    });
    
    for (int i = 0; i < n; i++) p.emplace_back(p[i]);
    
    long double ans = 0.0;
    for (int i = 0; i < n; i++) {
        long double y = p[i].first, x = p[i].second;
        long double res = sqrtl(y * y + x * x);
        for (int j = i+1; j < i+n; j++) {
            y += p[j].first; x += p[j].second;
            chmax(res, sqrtl(y * y + x * x));
        }
        chmax(ans, res);
    }
    
    cout << fixed << setprecision(30) << ans << endl;
    return 0;
}