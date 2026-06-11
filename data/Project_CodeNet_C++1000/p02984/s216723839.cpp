#include <bits/stdc++.h>
#include <boost/range/adaptor/reversed.hpp>
#include <boost/range/algorithm/sort.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using boost::irange;
using boost::sort;
using boost::adaptors::reversed;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            ans[0] += a[i];
        } else {
            ans[0] -= a[i];
        }
    }

    for (int i = 1; i < n; i++) ans[i] = 2 * a[i - 1] - ans[i - 1];

    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}
