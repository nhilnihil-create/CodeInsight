#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

double kaizyou(double n) {
    double ans = 1;
    while(n) {
        ans *= n;
        n--;
    }
    return ans;
}

int main() {
    double n;
    double ans = 0;
    cin >> n;
    vector<double> x(n), y(n), order(n);
    rep(i, n) {
        cin >> x[i] >> y[i];
        order[i] = i;
    }
    do {
        double tmp = 0;
        rep(i, n - 1) {
            tmp += sqrt((x[order[i]] - x[order[i + 1]]) *
                            (x[order[i]] - x[order[i + 1]]) +
                        (y[order[i]] - y[order[i + 1]]) *
                            (y[order[i]] - y[order[i + 1]]));
        }
        ans += tmp;
    } while(next_permutation(order.begin(), order.end()));
    ans /= kaizyou(n);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}