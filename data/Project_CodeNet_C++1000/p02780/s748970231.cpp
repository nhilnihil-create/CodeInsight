#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    fixed(cout);

    int n, k; cin >> n >> k;
    vector<double> csum(n + 1);
    csum[0] = 0;

    for (int i = 1; i <= n; ++i) {
        int p; cin >> p;
        auto ave = (p * (p + 1) / 2) / double(p);

        csum[i] = csum[i - 1] + ave;
    }

    double ans = 0;
    for (int i = k; i <= n; ++i) {
        ans = max(ans, csum[i] - csum[i - k]);
    }

    cout << ans << endl;
}

