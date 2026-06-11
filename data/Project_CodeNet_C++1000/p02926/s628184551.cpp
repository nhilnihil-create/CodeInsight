#include "bits/stdc++.h"
using namespace std;
typedef long long li;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    li n;
    cin >> n;

    vector<complex<double>> points;
    vector<pair<double, li>> args;
    for (int i = 0; i < n; ++i) {
        li x, y;
        cin >> x >> y;
        complex<double> p(x, y);
        points.emplace_back(p);
        args.emplace_back(arg(p), i);
    }

    sort(args.begin(), args.end());

    double ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            complex<double> sum = 0;
            if (j <= i) {
                for (int k = 0; k < j; ++k) {
                    sum += points[args[k].second];
                }
                for (int k = i; k < n; ++k) {
                    sum += points[args[k].second];
                }
            } else {
                for (int k = i; k < j; ++k) {
                    sum += points[args[k].second];
                }
            }
            ans = max(ans, abs(sum));
        }
    }

    cout << setprecision(24) << ans << endl;
    return 0;
}