#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int x, n;   cin >> x >> n;
    int *p = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    sort(p, p+n);

    int a = 9999;
    int ans;
    for (int k = -1; k <= 101; k++) {
        if (a > abs(x-k) && *(lower_bound(p, p+n, k)) != k) {
            a = abs(x-k);
            ans = k;
        }
    }
    cout << ans << endl;

    return 0;
}