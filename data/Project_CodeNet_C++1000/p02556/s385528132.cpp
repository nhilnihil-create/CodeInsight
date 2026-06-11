#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> z(n);
    vector<long long> w(n);

    for(long long i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        z[i] = x + y;
        w[i] = x - y;
    }

    sort(z.begin(), z.end());
    sort(w.begin(), w.end());

    long long maxz = z[n-1];
    long long minz = z[0];
    long long maxw = w[n-1];
    long long minw = w[0];

    long long ans = max(maxz - minz, maxw - minw);

    cout << ans << endl;
    return 0;
}