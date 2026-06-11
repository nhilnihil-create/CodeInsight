#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, v, p;
    cin >> n >> m >> v >> p;
    vector<long long> A;
    A.reserve(n);
    copy_n(istream_iterator<long long>(cin), n, back_inserter(A));
    sort(A.begin(), A.end());

    auto ok = [&](int i) {
        auto last_it = upper_bound(A.begin(), A.end(), A[i]);
        --last_it;
        i = distance(A.begin(), last_it);
        if (i >= n - p) {
            return true;
        }
        auto w = max(0, v - p - i);
        long long ai = A[i] + m;
        long long todo = 0;
        for (int j = i + 1; j < n - (p - 1); ++j) {
            if (A[j] <= ai) {
                todo += ai - A[j];
            } else {
                return false;
            }
        }
        return todo >= (long long)m * w;
    };

    int ans;
    if (ok(0)) {
        ans = n;
    } else {
        int a = 0;
        int b = n - 1;
        while (b - a > 1) {
            int c = a + (b - a) / 2;
            if (ok(c)) {
                b = c;
            } else {
                a = c;
            }
        }
        ans = n - b;
    }
    cout << ans << endl;
    return 0;
}
