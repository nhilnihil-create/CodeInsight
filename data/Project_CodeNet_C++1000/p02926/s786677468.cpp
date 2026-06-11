#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

struct Engine {
    double x, y;
    double radius;
    
    bool operator<(const Engine &a) {
        return radius < a.radius;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    long double PI = 3.141592653589793238462643383;
    ll n;
    cin >> n;
    vector<Engine> engines(n);
    rep(i, n) {
        cin >> engines[i].x >> engines[i].y;
        engines[i].radius = atan2(engines[i].y, engines[i].x);
    }
    sort(all(engines));
    double ans = -1;
    reps(size, 1, n + 1) {
        rep(offset, n) {
            double x = 0, y = 0;
            reps(i, offset, offset + size) {
                x += engines[i % n].x;
                y += engines[i % n].y;
            }
            double tmp = sqrt(x * x + y * y);
            ans = max(ans, tmp);
        }
    }
    printf("%.20f\n", ans);
    return 0;
}
