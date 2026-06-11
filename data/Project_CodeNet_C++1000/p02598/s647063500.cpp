#include <bits/stdc++.h>

#include <vector>
using namespace std;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define deg_to_rad(deg) (((deg) / 360) * 2 * M_PI)
#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

typedef long long ll;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    int l = 0, r = 1e9;
    while (r - l > 1) {
        int x = (l + r) / 2;
        auto f = [&](int x) {
            ll now = 0;
            rep(i, N) {
                now += (A[i] - 1) / x;
            }
            return now <= K;
        };
        if (f(x)) {
            r = x;
        } else {
            l = x;
        }
    }
    cout << r << endl;
    return 0;
}
