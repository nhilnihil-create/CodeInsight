#include <bits/stdc++.h>
using namespace std;
int a[200014], b[200014];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    int m1, m2;
    if (n & 1 == 1) {
        m1 = a[(n-1)/2];
        m2 = b[(n-1)/2];
    } else {
        m1 = a[n/2-1] + a[n/2];
        m2 = b[n/2-1] + b[n/2];
    }
    cout << m2 - m1 + 1 << endl;
    return 0;
}