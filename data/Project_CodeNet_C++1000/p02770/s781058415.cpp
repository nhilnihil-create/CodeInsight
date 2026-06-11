#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, q; cin >> k >> q;
    vector<long long> D(k), d(k);
    for(int i=0; i<k; ++i) cin >> D[i];

    while(q--) {
        long long n, x, m; cin >> n >> x >> m;
        x %= m;
        long long sum = 0;
        for(int i=0; i<k; ++i) {
            d[i] = D[i] % m;
            if(d[i] == 0) d[i] = m;
            sum += d[i];
        }
        long long tmp = x + sum * ((n - 1) / k);
        for(int i=0; i<(n-1)%k; ++i) tmp += d[i];
        cout << n - 1 - (tmp / m) << endl;
    }
}
