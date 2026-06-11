#include <bits/stdc++.h>
#include <boost/range/adaptor/reversed.hpp>
#include <boost/range/algorithm/sort.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using boost::irange;
using boost::sort;
using boost::adaptors::reversed;

int main() {
    int n, m = 0;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i : irange(1, n + 1) | reversed) {
        bool odd = false;
        for (int j = 2; j * i <= n; j++) if (b[j * i]) odd = !odd;
        m += b[i] = odd != a[i];
    }

    cout << m << endl;
    for (int i = 1; i <= n; i++) if (b[i]) cout << i << " ";
    if (m) cout << endl;
}
