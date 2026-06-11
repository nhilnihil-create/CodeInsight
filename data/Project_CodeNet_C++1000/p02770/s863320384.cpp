#include <numeric>
#include <iostream>
using namespace std;
int main() {
    int k, q; cin >> k >> q;
    int d[k];
    for (int i = 0; i < k; i++) cin >> d[i];
    while (q--) {
        int n, x, m; cin >> n >> x >> m;
        long long s[k+1] = {0};
        for (int i = 1; i <= k; i++) {
            int t = d[i-1] % m;
            s[i] = (t > 0 ? t : m) + s[i-1];
        }
        int qn = (n-1)/k, r= (n-1)%k;
        long long an = x + qn * s[k] + s[r],
            q0 = x / m, q1 = an / m;
        cout << n - 1 - (q1 - q0) << endl;
    }
}
