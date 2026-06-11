#include <bits/stdc++.h>
using namespace std;
int main () {
    int N;
    cin >> N;
    vector<int> A(N);
    int p = 0, m = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] >= 0) p++;
        else m++;
    }
    sort(A.begin(), A.end());
    if (p == 0) {
        m--;
        p++;
    }
    if (m == 0) {
        m++;
        p--;
    }
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        ans += -A[i];
    }
    for (int i = m; i < N; i++) {
        ans += A[i];
    }
    cout << ans << endl;
    long long x = A[0];
    for (int i = 0; i < p-1; i++) {
        cout << x << " " << A[m+i] << endl;
        x = x-A[m+i];
    }
    cout << A[N-1] << " " << x << endl;
    x = A[N-1]-x;
    for (int i = 1; i < m; i++) {
        cout << x << " " << A[i] << endl;
        x = x-A[i];
    }
}