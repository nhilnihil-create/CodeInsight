#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;

    vec<int> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];

    auto distance = [](long double x1, long double x2, long double y1,
                       long double y2) {
        long double dx = x2 - x1;
        long double dy = y2 - y1;
        return sqrt(dx * dx + dy * dy);
    };

    double sm = 0;
    ll cnt    = 0;

    function<void(vec<int>)> dfs = [&](vec<int> d) {
        if (d.size() == N) {
            rep(i, N - 1) {
                int a = d[i];
                int b = d[i + 1];

                sm += distance(x[a], x[b], y[a], y[b]);
            }
            ++cnt;
        }
        rep(i, N) {
            if (find(all(d), i) != d.end()) continue;
            d.push_back(i);
            dfs(d);
            d.pop_back();
        }
    };

    dfs(vec<int>(0));

    cout << fixed << setprecision(15);
    cout << sm/cnt << endl;
}
