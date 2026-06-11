#include <bits/stdc++.h>
using namespace std;

int n, m, a[1001], nr, sum;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] * 4 * m >= sum) {
            nr++;
        }
    }
    if(nr >= m) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
