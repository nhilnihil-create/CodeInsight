#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    vector<long long> b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<long long> A(n+1);
    A[0] = 0;
    vector<long long> B(m+1);
    B[0] = 0;
    for (int i = 0; i < n; i++) {
        A[i+1] = A[i] + a[i];
    }
    for (int i = 0; i < m; i++) {
        B[i+1] = B[i] + b[i];
    }
    int ans = 0;
    int j = m;
    for (int i = 0; i < n+1; i++) {
        if (A[i] > k) {
            break;
        }
        while (B[j] > k - A[i]) {
            j--;
        }
        ans = max(ans, i+j);
    }
    cout << ans << endl;
    return 0;
}